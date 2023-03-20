#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv) 
{
	MYSQL *conn;
	int err;
	//Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//Inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "LaserTails",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//Escribir en teclado el jugador con mayores puntos
	char consulta [150];
	strcpy (consulta,"SELECT Jugadores.nombre FROM Participaciones, Jugadores WHERE Participaciones.puntos = (SELECT MAX(Participaciones.puntos) FROM Participaciones) AND Participaciones.idJ = Jugadores.id");
	
	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recogemos el resultado de la consulta
	resultado = mysql_store_result (conn); 
	// Ahora obtenemos la primera fila
	row = mysql_fetch_row (resultado);
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		printf ("El record de puntos es: %s\n", row [0] );
	
	mysql_close (conn);
	exit(0);
}
