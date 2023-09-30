import mysql.connector
import datetime

# Configuración de la base de datos MySQL
db_config = {
    "host": "localhost",
    "user": "root",        # Reemplaza con tu nombre de usuario de MySQL
    "password": "8704",  # Reemplaza con tu contraseña de MySQL
    "database": "monitoreo_temperatura"
}

# Función para insertar datos en la base de datos
def insertar_lectura(temperatura, humedad, ubicacion, dispositivo):
    try:
        conexion = mysql.connector.connect(**db_config)
        cursor = conexion.cursor()

        # Insertar datos en la base de datos
        insert_query = "INSERT INTO lecturas_temperatura (fecha_hora, temperatura, humedad, ubicación, dispositivo) VALUES (%s, %s, %s, %s, %s)"
        values = (datetime.datetime.now(), temperatura, humedad, ubicacion, dispositivo)
        cursor.execute(insert_query, values)
        conexion.commit()
        print("Datos ingresados en la base de datos.")

    except Exception as e:
        print("Error:", str(e))

    finally:
        if conexion.is_connected():
            cursor.close()
            conexion.close()

try:
    while True:
        # Simula la lectura de datos desde el puerto serie o utiliza input() para pruebas
        datos = input("Ingresa los datos (temperatura, humedad, ubicación, dispositivo): ")
        temperatura, humedad, ubicacion, dispositivo = datos.split(',')

        # Llama a la función para insertar los datos en la base de datos
        insertar_lectura(float(temperatura), float(humedad), ubicacion, dispositivo)

except KeyboardInterrupt:
    print("Proceso interrumpido por el usuario.")

