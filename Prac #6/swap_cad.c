#include <stdio.h>

void swap_cadena(char *cad1ptr,char *cad2ptr);

int main() {
    char cadena1[80]="Esta es la primera cadena";
    char cadena2[80]="Esta es la segunda cadena";

    printf("%s\n",cadena1);
    printf("%s\n",cadena2);

swap_cadena(cadena1,cadena2);



printf("%s\n",cadena1);
printf("%s\n",cadena2);



  return 0;
}

void swap_cadena(char *cad1ptr,char *cad2ptr) {
  char aux;

  while ((*cad2ptr)!='\0') {
    aux=*(cad1ptr);
    *(cad1ptr++) = *(cad2ptr++);
    *(cad2ptr-1)=aux;
  }

  *cad1ptr='\0'; /*agregamos caracter vacio*/
  *cad2ptr='\0';
}



/*Formar alterna de hacerlo*/

/*

for (int i = 0; *(cad2ptr+i)!='\0'; i++) {
  aux=*(cad1ptr+i);
  *(cad1ptr+i) = *(cad2ptr+i);
  *(cad2ptr+i)=aux;
}
*cad1ptr='\0';
*cad2ptr='\0';

*/
