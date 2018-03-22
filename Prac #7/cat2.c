#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char buffer[90];
  int cont=0;
    FILE* file;

  if (argc<2 || argc>2) {
    printf("%s\n","Error, se espera un argumento.");
    printf("%s\n","Ejemplo:" );
    printf("%s\n","prac7.exe doc.txt" );
  }

  file=fopen(argv[1],"r");

  if (file==NULL) {
    printf("%s\n","Error al abrir archivo" );
    return (-1);
  }

  do {
    cont++;
    fgets(buffer,90,file);
    printf("%s",buffer );
    if (cont==15) {
      cont=0;
      printf("%s\n", "presione enter para continuar.");
      getchar();
    }
  } while(!feof(file));

  return EXIT_SUCCESS;
}
