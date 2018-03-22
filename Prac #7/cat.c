#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    FILE* file;
    char c;
    int i=0,a=15;

    if(argc<2 || argc>2)
    {
      printf("%s\n","Error, se espera un argumento.");
      printf("%s\n","Ejemplo:" );
      printf("%s\n","prac7.exe doc.txt" );
        exit(-1);
    }

    file = fopen(argv[1], "r");

    if (file==NULL) {
      printf("%s\n","Error al abrir archivo" );
      return (-1);
    }

c=fgetc(file);
while(!feof(file)){
  printf("%c",c);
  c=fgetc(file);
  if (c=='\n') {
      i++;
  }
  if (i==a) {
    a=10;
    i=0;
    printf("%s\n","Enter para continuar." );
    getchar();
  }


}


    fclose(file);
    return EXIT_SUCCESS;
}
