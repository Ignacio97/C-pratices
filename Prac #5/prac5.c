#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "lib5.h"

#define practicas 2 /*col*/
#define alumnos 2  /*row*/
#define size 100

void menu();

/*** INICIA MAIN ***/
int main() {

struct Alumno alum[alumnos];
struct Practica prac[practicas];
int tabla [alumnos][practicas],num;
char opcion;


genera_cal(tabla,alumnos,practicas);
llena_alumno(alum,tabla,alumnos,practicas);
llena_prac(prac,tabla,alumnos,practicas);



do{
	menu();
	scanf(" %c",&opcion);
	getchar();//Elimina los espacios en blanco del buffer de entrada.

	switch (opcion) {

		case 'a':
      imprime_matriz(tabla,alumnos,practicas);
		break;

		case 'b':
        printf("%s","No. de alumno:" );
        scanf("%d",&num );
        imprime_alumno(alum,num-1);
		break;

		case 'c':
        printf("%s","No. de practica:" );
        scanf("%d",&num );
        print_prac(prac,num-1);
		break;

		case 'd':
        print_all_student(alum);
		break;

		case 'e':
        print_all_prac(prac);
		break;

    case 'f':
        print_high_prom(alum);
    break;

    case 'g':
        print_reprobados(alum);
    break;

    case 'h':
        prac_reprobadas(prac);
    break;
		case 'i':
			printf("%s\n","Saliendo..." );

			break;

		default:
			printf("%s\n","Opcion no valida!" );
		break;

	}


}while(opcion!='i');

	return 0;

}
/*** TERMINA MAIN ***/

/** INICIO DE FUNCIONES **/

//Fun. que despliega el menu del prog.
void menu(){
	printf("\n");
	printf("\t*** Practica 5: Estructuras​ ​de​ ​datos. ***");
  printf("\n\n\r[a] Mostrar tabla de calificaciones. " );
  printf("\n\r[b] Mostrar toda inf. de un alum. indicado por el usuario. ");
  printf("\n\r[c] Mostrar toda inf. de una prac. indicada por el usuario.");
  printf("\n\r[d] Mostrar lista de alumnos.");
  printf("\n\r[e] Mostrar lista de prac.");
  printf("\n\r[f] Mostrar alumno con mayor promedio.");
  printf("\n\r[g] Mostrar alumnos reprobados.");
  printf("\n\r[h] Mostrar prac. con promedio menor a 6.");
  printf("\n\r[i] EXIT");
  printf("\n\n\rSELECCIONE UNA OPCION:");
}
/** FINAL DE FUNCIONES**/
