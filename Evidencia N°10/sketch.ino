#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Definición de pines del sensor DHT
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Dirección I2C para la pantalla LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Configuración de WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configuración del Servidor MQTT
const char* mqtt_server = "iotpintar.net";
const int mqtt_port = 1883;
const char* mqtt_user = "";
const char* mqtt_password = "";

// Objetos del cliente WiFi y MQTT
WiFiClient espClient;
PubSubClient client(espClient);

float humedad;
float temperatura;

void configurar_wifi() {
  delay(10);
  // Comenzar conectándose a la red WiFi
  Serial.println();
  Serial.print("Conectándose a ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);

  configurar_wifi();

  // Inicializar cliente MQTT
  client.setServer(mqtt_server, mqtt_port);
  // Configurar la función de devolución de llamada cuando llega un mensaje
  client.setCallback(callback);

  // Inicializar el sensor DHT
  dht.begin();

  // Inicializar la pantalla LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Panel de Informacion");
  lcd.setCursor(0, 1);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 2);
  lcd.print("Humedad:");
  lcd.setCursor(0, 3);
  lcd.print("por Maxi Gimenez");
  delay(3000);
  lcd.clear();
}

// Función de devolución de llamada MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  // Esta función se llamará cuando llegue un mensaje desde el servidor MQTT
  // Puedes agregar la lógica apropiada aquí.
}

void reconectar() {
  // Reintentar la conexión hasta que el cliente esté conectado al servidor MQTT
  while (!client.connected()) {
    Serial.print("Intentando conectar al servidor MQTT...");
    if (client.connect("ClienteESP32", mqtt_user, mqtt_password)) {
      Serial.println("Conectado al servidor MQTT");
    } else {
      Serial.print("Fallo, código de estado = ");
      Serial.print(client.state());
      Serial.println(" Intentando nuevamente en 5 segundos");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconectar();
  }
  client.loop();

  humedad = dht.readHumidity();
  temperatura = dht.readTemperature();

  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer datos del sensor DHT22");
    return;
  }
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Panel de Informacion");
  lcd.setCursor(2, 1);
  lcd.print("Temperatura y Humedad");
  lcd.setCursor(0, 2);
  lcd.print("Temperatura :");
  lcd.setCursor(13, 2);
  lcd.print(temperatura);
  lcd.setCursor(19, 2);
  lcd.print("C");

  lcd.setCursor(0, 3);
  lcd.print("Humedad :");
  lcd.setCursor(13, 3);
  lcd.print(humedad);
  lcd.setCursor(19, 3);
  lcd.print("%");

  // Enviar datos al servidor MQTT
  String topic_humedad = "polines/Ik2c/33422202/RH";
  String topic_temperatura = "polines/Ik2c/33422202/RT";
  client.publish(topic_humedad.c_str(), String(humedad).c_str());
  client.publish(topic_temperatura.c_str(), String(temperatura).c_str());

  delay(2000);
  lcd.clear();
}
