#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libf9.h"

void menu() {
  CLEAR();
  printf("Ordenar por:\n" );
  printf("[1].ID\n");
  printf("[2]Clase.\n");
  printf("[3]Nombre.\n");
  printf("[4]Telefono.\n");
  printf("[5]Contenido.\n");
  printf("[6]Fecha.\n");
  printf("[8]Imprimir registros.\n");
  printf("[9]Generar respaldo.(Ordenado)\n");
  printf("[0]EXIT\n");
  printf("Seleccione un opcion:");
}

int llena_array(ADVERT **registros) {
  FILE* flujo=NULL;

  int i=0;
flujo=fopen("data.dat","rb");
  if(!flujo)
    printf("ERROR AL ABRIR ARCHIVO!\n" );

    *registros=(ADVERT*)malloc(sizeof(ADVERT));
if (*registros==NULL) {
  printf("puntero NULL\n" );
}

while (fread(*registros+i,sizeof(ADVERT),1,flujo)>0) {
  i++;
  *registros=(ADVERT*)realloc(*registros,(i+1)*sizeof(ADVERT));
}

  fclose(flujo);
  return i;
}

  int crea_array_ptr(ADVERT ***ptr){

ADVERT *registro=NULL;
int n;
n=llena_array(&registro);

*ptr=(ADVERT**)malloc(n*sizeof(ADVERT*));


for (int j = 0; j < n; j++) {
    *(*ptr+j)=registro+j;
}
return n;

}

void ordena(int (*comparar)(void **a,void **b)){
ADVERT** array=NULL;
int cont=0;

cont=crea_array_ptr(&array);
bubbleSort(array,cont,comparar);
prime_anuncio(array,cont);

free (array);

}

void prime_anuncio(ADVERT**registro,int n) {
char *meses[]={"ENE","FEB","MAR","ABR","MAY","JUN","JUL","AGO","SEP","OCT","NOV","DIC"};
  for (int i = 0; i < n; i++) {

  printf("--------------------------------\n" );
  printf("\n\t Registro No. %d\n",i+1 );
  printf("ID: %d\n",registro[i]->id );
  printf("Clase:%s\n",registro[i]->clase);
  printf("Titular:%s",registro[i]->titular );
  printf("Telefono:%ld\n",registro[i]->telefono );
  printf("Contenido:%s",registro[i]->contenido );
  printf("Fecha:%d/%s/%d\n",registro[i]->fecha.dia,meses[(registro[i]->fecha.mes)-1],registro[i]->fecha.year );

}
fseek(stdin,0,SEEK_END);
getchar();
}
void bubbleSort(void **array, int n, int (*cmp)( void**a, void**b)){
    int i,j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(cmp(array+i, array+j) > 0)
                swap(array+i, array+j);
}

void swap( void** a, void**b){
	ADVERT *aux;

  aux=*(ADVERT**)a;
  *(ADVERT**)a=*(ADVERT**)b;
  *(ADVERT**)b=aux;
}


int compara_id(void** a,void**b){

ADVERT A= **(ADVERT**)a;
ADVERT B=**(ADVERT**)b;

return (A.id-B.id);
}

int compara_nombre(void** a,void**b){

ADVERT A= **(ADVERT**)a;
ADVERT B=**(ADVERT**)b;

return (strcasecmp(A.titular,B.titular));
}

int compara_clase(void** a,void**b){

ADVERT A= **(ADVERT**)a;
ADVERT B=**(ADVERT**)b;

return (strcasecmp(A.clase,B.clase));
}

int compara_telefono(void** a,void**b){

ADVERT A= **(ADVERT**)a;
ADVERT B=**(ADVERT**)b;

return (A.telefono-B.telefono);
}
int compara_contenido(void** a,void**b){

ADVERT A= **(ADVERT**)a;
ADVERT B= **(ADVERT**)b;

return (strcasecmp(A.contenido,B.contenido));
}

int compara_fecha(void** a,void**b){

ADVERT A=**(ADVERT**)a;
ADVERT B=**(ADVERT**)b;

return ((A.fecha.year*10000+A.fecha.mes*100+A.fecha.dia)-(B.fecha.year*10000+B.fecha.mes*100+B.fecha.dia) );
}
void display() {

  char *meses[]={"ENE","FEB","MAR","ABR","MAY","JUN","JUL","AGO","SEP","OCT","NOV","DIC"};
  FILE *file;
  ADVERT registro;
  int cont=1;

  file=fopen("data.dat","rb");

  if (file) {

    while (fread(&registro,sizeof(ADVERT),1,file)>0) {
      printf("--------------------------------\n" );
      printf("\n\t Registro No. %d\n",cont );
      printf("ID: %d\n",registro.id );
      printf("Clase:%s\n",registro.clase);
      printf("Titular:%s",registro.titular );
      printf("Telefono:%ld\n",registro.telefono );
      printf("Contenido:%s",registro.contenido );
      printf("Fecha:%d/%s/%d\n",registro.fecha.dia,meses[(registro.fecha.mes)-1],registro.fecha.year );
      cont++;
    }
    while(getchar()!='\n');//Limpia buffer
    getchar();
  }
  else{
    printf("No se encontro registro!!\n" );
fseek(stdin,0,SEEK_END);
    getchar();}
  fclose(file);
}

void respaldo(int opc) {
  FILE *destino=NULL;
  int cont=0;
  ADVERT **array;

cont=crea_array_ptr(&array);


destino=fopen("respaldo.dat","wb");

if (destino==NULL){
 printf("ARCHIVO DESTINO NO CREADO! \n");
 fseek(stdin,0,SEEK_END);
 getchar();

}

switch (opc) {

  case 1:
      bubbleSort(array,cont,compara_id);
    break;

    case 2:
    bubbleSort(array,cont,compara_clase);
      break;

    case 3:
    bubbleSort(array,cont,compara_nombre);
      break;

  case 4:
  bubbleSort(array,cont,compara_telefono);
  break;

  case 5:
  bubbleSort(array,cont,compara_contenido);
  break;

  case 6:
  bubbleSort(array,cont,compara_fecha);
  break;
}



for (int i = 0; i < cont; i++) {
fwrite(*(array+i),sizeof(ADVERT),1,destino);
}

fclose(destino);
remove("data.dat");
rename("respaldo.dat","data.dat");

printf("\n\nDONE..!\n" );
fseek(stdin,0,SEEK_END);
getchar();



}
