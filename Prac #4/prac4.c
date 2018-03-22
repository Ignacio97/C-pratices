#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "library4.h"

# define alumnos 20        /*row*/
# define practicas 10		/*col*/

/*PRPTOTIPO DE FUNCION */
void menu();
void wait_enter();
/*FIN*/

/*** INICIA MAIN ***/
int main(){
	int matriz[alumnos][practicas],Maux[alumnos][practicas],practica,alumno;
	float promedio=0;
	char opcion;

	genera_cal(matriz,alumnos,practicas);
	copia_matriz(matriz,Maux,alumnos,practicas);
	bubbleSort​(Maux,alumnos,practicas);
do{
	menu();
	scanf(" %c",&opcion);
	getchar();//Elimina los espacios en blanco del buffer de entrada.

	switch (opcion) {
		
		case 'a':
			imprime_matriz(matriz,alumnos,practicas);
			wait_enter();
		break;

		case 'b':
			printf("%s","Capture numero de practica:" );
			scanf("%d",&practica);
			promedio=prom_cal(matriz,alumnos,practicas,practica);
			prom_imprime(practica,promedio,opcion);
			wait_enter();
		break;

		case 'c':
			printf("%s","Capture numero del alumno:" );
			scanf("%d",&alumno);
			promedio=promAlumno(matriz,alumnos,practicas,alumno);
			prom_imprime(alumno,promedio,opcion);
			wait_enter();
		break;

		case 'd':

			printf("La media es: %.2f",media(Maux,alumnos,practicas) );
			printf("\nLa mediana es:%.2f",mediana(Maux,alumnos,practicas));
			printf("\nLa moda es:%d", moda(Maux,alumnos,practicas));
			wait_enter();
		break;

		case 'e':
			imprime_matriz(Maux,alumnos,practicas);
			wait_enter();
		break;
		
		case 27:
			printf("%s\n","Saliendo..." );
			
			break;

		default:
			printf("%s\n","Opcion no valida!" );
		break;

	}

	//wait_enter();

}while(opcion!=27); //27 = 'ESC' en codigo ascII

	return 0;
}

/*** TERMINA MAIN ***/


/*** INICIO DE FUNCIONES ***/

void menu(){
	printf("\n");
	printf("\t*** Practica 4: Estructuras​ ​de​ ​control. ***");
  printf("\n\n\r[a] Mostrar tabla de calificaciones. " );
  printf("\n\r[b] Mostrar cal. de un prac. indicado por el usuario. ");
  printf("\n\r[c] Mostrar cal. de un alum. indicada por el usuario.");
  printf("\n\r[d] Mostrar moda, mediana y media de calificaciones.");
  printf("\n\r[e] Mostrar matriz ordenada.");
  printf("\n\r[ESC] EXIT");
  printf("\n\n\rSELECCIONE UNA OPCION:");
}

//Fun. que espera a que el usuario presione enter.
void wait_enter(){
  setbuf(stdin, NULL); // Limpia el buffer de estrada.
      getchar();
}
/*** FIN DE FUNCIONES ***/

