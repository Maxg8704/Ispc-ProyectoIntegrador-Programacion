<img src="https://github-production-user-asset-6210df.s3.amazonaws.com/86580762/237179645-e4bb6ff9-0bb5-441d-a98f-a4a6a53577e6.jpg">

## **PROYECTO INTEGRADOR**

### **Institución: Instituto Superior Politécnico Córdoba.**

<hr>

### **Tecnicatura en Telecomunicaciones**

<hr>

### **Materia:** Programacion

<hr>

### **Profesor:** Ing. Lisandro Lanfranco

<hr>

### **Año:** 2023

<hr>

### **Alumno:**  

* **<a href="https://github.com/Maxg8704">Jose Maximiliano Gimenez</a>**
<hr>

## Proyecto Integrador 2° Cuatrimestre. 

**Condiciones generales de entrega:**

    Trabajo individual.

    Entrega de evidencias por Moodle. Adicionalmente puede utilizarse Github como repositorio.

**Criterios de evaluación:**

    Cumplimentar TODAS las consignas.

    Desarrollo del prototipo:

        Identificación de los componentes y conexionado físico

        Programa embebido

        Almacenamiento de información en Base de Datos


**Fecha de entrega:**

    Entregas parciales en tiempo y forma.

    Proyecto completo al fin del 2° cuatrimestre


## **Docente:**

### **Profesor: Ing. Lisandro Lanfranco**
<hr>

### Objetivo del Proyecto

La empresa "Dispositivos Inteligentes SRL" nos ha encomendado la tarea de diseñar y desarrollar un nodo IoT (Internet de las Cosas) capaz de registrar al menos una variable importante en una base de datos. Este proyecto tiene como objetivo aplicar tus conocimientos en electrónica y programación de microcontroladores para crear un dispositivo inteligente que sea capaz de recopilar y almacenar datos relevantes.

El esquema general del sistema a desarrollar se muestra en la siguiente imagen:

## Objetivo del Proyecto

<hr>

El esquema general del sistema a desarrollar se muestra en la siguiente
imagen: 

<img src="https://blog.arduinoomega.com/wp-content/uploads/2022/07/image-768x519.png">

1. Se dispondrá de un sensor que mida una variable de interés.
2. Este sensor será conectado a un microcontrolador (Arduino o
similar), el cual enviará datos por puerto serie a una PC. Adicional a
esto, cuando la variable medida supere cierto umbral, se accionará
un actuador.
3. En esta PC correrá un programa, a desarrollar, en Python que leerá
el puerto serie, y enviará datos a un Sistema Gestor de Base de
Datos local.
4. Por último, nuestro SGDB, almacenará los datos recibidos desde el
programa Python cliente.

**Como diseñador a cargo del proyecto, su tarea consiste en los siguientes pasos:**
<hr>

## Entrega 1: Fecha de entrega (10/09/23)

Elegir una variable de interés que sea relevante, podría ser la
temperatura ambiente, la humedad, la luminosidad, la presión
atmosférica, o cualquier otro parámetro.
Seleccionar un sensor adecuado para medir la variable elegida. Asegúrate
de que el sensor sea compatible con el microcontrolador que utilizarás y
que proporcione lecturas precisas.
Documentar la elección y justificación de la variable y el sensor en un
informe técnico. Incluir un resumen de la hoja de datos del sensor en el
reporte que se entregara.
Nota: Si surgen dudas sobre la utilización del sensor, consultar con el
docente sobre cómo se interconecta.
Aclaración: No es necesario adquirir el sensor, sólo hacer la
selección y luego será simulado.
<hr>

## Entrega 2: Fecha de entrega (24/09/23)

Creación de la base de datos en MySQL para almacenar la información
que generará nuestro dispositivo.
Diseñar la estructura y crear tablas necesarias.
Proporcionar el esquema y el código de creación de la base de datos y las
tablas.

<hr>

## Entrega 3: Fecha de entrega (15/10/23)

Conectarse desde Python a la base de datos y escribir la información
recibida por puerto serie.
Para esto deberá leer el puerto serie con python y luego ingresar datos
(INSERT INTO) a la BD.

Nota: Aún no tenemos corriendo el dispositivo, por lo que puede utilizar
la función input() para generar información que ingrese al programa.

<hr>

## Entrega 4: Fecha de entrega (29/10/23)

El dispositivo que estamos diseñando debe relevar la información
producida por el Sensor, el nivel de batería del dispositivo y en base a un
úmbral elegido, accionar un Actuador.
Diseñar el esquema eléctrico y conectar el sensor al microcontrolador.
Escribir un programa que permita al microcontrolador recopilar datos del
sensor y prepararlos para su envío. Para esto, debe considerar la
capacidad de comunicación del microcontrolador.
Seleccionar un Actuador y realizar la programación del comportamiento
del mismo.
<hr>

## Entrega 5: Fecha de entrega (12/11/23)

Probar la comunicación completa entre el dispositivo IoT y la PC. Realizar
las correcciones necesarias y la optimización del sistema que consideres.
Proporcionar el código fuente y documentación de los programas que se
han escrito.
Documentar las pruebas realizadas, las correcciones y cambios que
realizados a lo largo del proyecto.
<hr>

## Entrega 6: Fecha de entrega (antes del fin de cuatrimestre)
Recuperación y defensa del trabajo.
Se deberán recuperar las entregas desaprobadas o que no fueron
entregadas y se realizará una defensa oral del proyecto.
Formato de entrega
Cada entrega debe incluir un informe claro y completo que explique los
detalles técnicos y las decisiones tomadas en cada etapa del proyecto.
Este informe debe ser subido a la plataforma del instituto antes de la
fecha límite.
Se podrán recuperar las entregas que no sean subidas a tiempo, con una
penalidad sobre la nota final.