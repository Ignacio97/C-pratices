#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib8.h"

#define SIZE 50
/*** INICIA MAIN ***/

int main() {
  char aux[SIZE],*clases[]={"Venta varios","Autos","Mascota","Empleo","Renta","Traspaso"};
  ADVERT sheet; //declaracion de "sheet" del tipo ADVERT.
  int opc;
    do {

        menu();
        setbuf(stdin,NULL);
        fscanf(stdin,"%d",&opc );

        switch (opc) {
          case 0:
          printf("SALIENDO...!\n" );
            break;
          case 1:
                captura(&sheet);
                save(sheet);
                setbuf(stdin,NULL);
                getchar();
              break;
          case 2:
                delete();
              break;
          case 3:
                editar();
              break;
          case 4:
            search_cate(clases[categoria()-1],opc);
              break;
          case 5:
            printf("Nombre del responsable:" );
            setbuf(stdin,NULL);
            fgets(aux,SIZE,stdin);
            search_cate(aux,opc);
              break;
          case 6:
              display();
              break;
          case 7:
            break;

          case 8:
            break;
          case 9:
              break;

          default:
              printf("%s\n","Opcion no disponible." );
              fseek(stdin,0,SEEK_END);
              getchar();
              break;
        }

      } while(opc!=0);




    return EXIT_SUCCESS;
  }

  /*** TERMINA MAIN ***/
