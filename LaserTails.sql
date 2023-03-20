DROP DATABASE IF EXISTS LaserTails;
CREATE DATABASE LaserTails;

USE LaserTails;

CREATE TABLE Jugadores(
	id INT PRIMARY KEY NOT NULL, 
	nombre VARCHAR(60) NOT NULL,
	contrasena VARCHAR(60) NOT NULL
)ENGINE=InnoDB;


CREATE TABLE Partidas (
	id INT PRIMARY KEY NOT NULL, 
	numjugadores INT NOT NULL,
	tiempo FLOAT NOT NULL
)ENGINE = InnoDB; 


CREATE TABLE Participaciones (
	idJ INT NOT NULL, 
	idP INT NOT NULL,
	puntos INT NOT NULL,
	color VARCHAR(60),
	FOREIGN KEY (idJ) REFERENCES Jugadores (id),
	FOREIGN KEY (idP) REFERENCES Partidas (id)
)ENGINE = InnoDB; 

INSERT INTO Jugadores VALUES(1,'Juan', 'cocacola');
INSERT INTO Jugadores VALUES(2,'Eustaquio', 'pepsi');
INSERT INTO Jugadores VALUES(3,'Rubius', 'wilson');
INSERT INTO Jugadores VALUES(4,'Roberta', 'hola123'); 

INSERT INTO Partidas VALUES(1, 2, 3.51);
INSERT INTO Partidas VALUES(2,2,5);
INSERT INTO Partidas VALUES(3,4,6);

INSERT INTO Participaciones VALUES(1,1,13,'rojo');
INSERT INTO Participaciones VALUES(2,1,10,'amarillo');
INSERT INTO Participaciones VALUES(3,2,15,'azul');
INSERT INTO Participaciones VALUES(4,3,20,'morado');

