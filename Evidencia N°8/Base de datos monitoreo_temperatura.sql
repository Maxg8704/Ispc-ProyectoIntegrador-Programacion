-- Crear la base de datos 

CREATE DATABASE monitoreo_temperatura; 

 
-- Usar la base de datos 

USE monitoreo_temperatura; 

 
-- Crear la tabla para almacenar las lecturas del sensor 

CREATE TABLE lecturas_temperatura ( 

	id INT AUTO_INCREMENT PRIMARY KEY, 

	fecha_hora DATETIME NOT NULL, 

	temperatura FLOAT NOT NULL, 

	humedad FLOAT NOT NULL, 

	ubicación VARCHAR (255), 

	dispositivo VARCHAR (255) 

); 