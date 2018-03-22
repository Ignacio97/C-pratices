#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libf9.h"

#define SIZE 50
/*** INICIA MAIN ***/

int main() {
     int opc,aux;
    do {
      menu();
      setbuf(stdin,NULL);
      fscanf(stdin,"%d",&opc );
        switch (opc) {
          case 0:
          printf("SALIENDO...!\n" );

            break;
          case 1:
            ordena(compara_id);
              break;
          case 2:
            ordena(compara_clase);
              break;
          case 3:
          ordena(compara_nombre);
              break;
          case 4:
          ordena(compara_telefono);
              break;
          case 5:
          ordena(compara_contenido);
              break;
          case 6:
          ordena(compara_fecha);
              break;

          case 8:
            display();
            break;
          case 9:
          respaldo(aux);
              break;

          default:
              printf("%s\n","Opcion no disponible." );
              fseek(stdin,0,SEEK_END);
              getchar();
              break;
        }
          if(opc>=1 && opc<=6)
            aux=opc;

      } while(opc!=0);




    return EXIT_SUCCESS;
  }

  /*** TERMINA MAIN ***/


  /*
  1.- ¿Qué configuración de apuntadores se requerirían para constituir la lista de
      elementos a ordenar?
      Para manipular varios elementos (estructura) se puede crear un arreglo de
  	apuntadores, ya que el archivo esta compuesto de unidades con la misma
  	longitud de bytes


  2.- ¿Cómo sería el prototipo de la función swap?
  	Función que recibe 2 direcciones para inicializarlas en apuntadores
      de tipo void, esto con el fin de que puedan manejar cualquier tipo de dato.
      void swap(void**,void**)


  3.- ¿Cómo sería el prototipo de la función compare?
    int (*cmp)(const void*, const void*)


  4.- ¿Cómo sería el prototipo de la función bubbleSort?
  	Función que recibe la dirección del arreglo que se utilizará, el numero de
  	elementos que contiene, la cantidad de bytes que ocupa cada elemento y
  	una función que especifique qué tipo de datos se ordenarán y cómo
  	se compararán.

      void bubbleSort(void* array, int n, int size, int (*cmp)(const void*, const void*));


  */
