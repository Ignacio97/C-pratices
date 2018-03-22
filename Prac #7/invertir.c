#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void invierte(FILE* file);
void cpy(FILE* fuente,FILE* destino);


int main(int argc, char *argv[]) {
  FILE *file=NULL,*destino=NULL;


if (argc==2) {

  file=fopen(argv[1],"r");
        if (file==NULL) {
            printf("%s\n","Error al abrir archivo" );
            return (-1);
          }
    invierte(file);


  }

  else if (argc==3) {
    file=fopen(argv[1],"r");
    destino=fopen(argv[2],"w+");

          if (file==NULL) {
              printf("%s\n","Error al abrir archivo" );
              return (-1);
            }

            cpy(file,destino);


    }
    else {
      printf("ERROR!!\n");
      printf("Se espera:\n" );
      printf("cat.exe file.txt\n");
      printf("cat.exe name.txt newname.txt\n");
    }


fclose(file);

  return EXIT_SUCCESS;
}


void invierte(FILE* file){
  char c;

  //c=fgetc(file);
  while (!feof(file)) {
      c=fgetc(file);
      if(c>=65 && c<=90){
        printf("%c",c+32 );
      }
        else if (c>=97 && c<=122) {
            printf("%c",c-32);
          }
            else{
              printf("%c",c );
              }
     //c=fgetc(file);
  }
printf("\n\n"); //imprime salto de linea cuando termina el programa.

}

void cpy(FILE* fuente,FILE* destino){
  char c;

  c=fgetc(fuente);
  while (!feof(fuente)) {
      if(c>=65 && c<=90){
        fputc(c+32,destino);
      }
        else if (c>=97 && c<=122) {
          fputc(c-32,destino );
          }
            else{
              fputc(c,destino );
              }
     c=fgetc(fuente);
  }

}
