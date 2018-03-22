#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib10.h"

#define SIZE 50
  /** INICIO DE FUNCIONES **/


int menu_editar(){
  int op;

  printf("\n");
  printf("EDITAR:\n");
  printf("[1]Clasificacion\n");
  printf("[2]Responsable.\n");
  printf("[3]Telefono.\n");
  printf("[4]Contenido.\n");
  printf("[5]Fecha.\n");
  printf("[6]Todo el contenido.\n");
  printf("Selecciones una opcion: ");
  setbuf(stdin,NULL);
  fscanf(stdin,"%d",&op);

  return op;
}

int categoria() {
  int opc;


  printf("\n");
  printf("\t\t[1]Venta Varios.\n");
  printf("\t\t[2]Autos.\n");
  printf("\t\t[3]Mascota.\n");
  printf("\t\t[4]Empleo.\n");
  printf("\t\t[5]Renta.\n");
  printf("\t\t[6]Traspaso.\n");
  printf("\t\tSelecciones una opcion: " );
  setbuf(stdin,NULL);
  fscanf(stdin,"%d",&opc);

  return opc;
}



void menu() {
  CLEAR();
  printf("[1]Registrar anuncio.\n");
  printf("[2]Cancelar anuncio.(By ID)\n");
  printf("[3]Editar anuncio.(By ID)\n");
  printf("[4]Consulta por clasificacion.\n");
  printf("[5]Consulta por responsable.\n");
  printf("[6]Mostrar todos los registros.\n");
  printf("[7]Mostrar todos los registro en la fecha actual.\n");
  printf("[8]Ordenar por responsable.\n");
  printf("[9]Mostrar por clasificacion(en orden).\n");
  printf("[10]Mostrar por id.(en orden)\n");
  printf("[11]Generar respaldo.\n");
  printf("[0]EXIT\n");
  printf("Seleccione un opcion:");
}

void captura(ADVERT *ad){

    char *clases[]={"Venta varios","Autos","Mascota","Empleo","Renta","Traspaso"},key[SIZE];

  CLEAR();
  printf("ID:");
  while(getchar()!='\n');
 fgets(key,SIZE,stdin);

  while (search(key)!=-1) {
  printf("ID REGISTRADO!!\n");
  printf("ID:");
  fgets(key,SIZE,stdin);
  }
  ad->id=atoi(key);
  setbuf(stdin,NULL); //Limpia el buffer de entrada.
  printf("Clasificacion:");     strcpy(ad->clase,clases[(categoria())-1]);
  setbuf(stdin,NULL);
  printf("Responsable:");      fgets(ad->titular,SIZE,stdin);  setbuf(stdin,NULL);
  printf("Telefono:");          scanf("%ld",&ad->telefono);
  setbuf(stdin,NULL); //Limpia el buffer de entrada.
  printf("Contenido:");          fgets(ad->contenido,SIZE,stdin);  setbuf(stdin,NULL);
  printf("Fecha (dd/mm/yyyy):");   scanf("%d%d%d",&ad->fecha.dia,&ad->fecha.mes,&ad->fecha.year);
setbuf(stdin,NULL);
}


void save(ADVERT ad) {
  FILE *file=NULL;

  file=fopen("data.dat","ab");

      if (file!=NULL ) {
          fwrite(&ad,sizeof(ADVERT),1,file);
          fclose(file);
          printf("SAVED..\n");
        }
      else{
            printf("No se pudo abrir!!\n");
        }

      }


//Fun. que imprime los datos.
void print(ADVERT *ad) {
  char *meses[]={"ENE","FEB","MAR","ABR","MAY","JUN","JUL","AGO","SEP","OCT","NOV","DIC"};
    printf("ID:%d\n",ad->id);
    printf("Clase:%s\n",ad->clase);
    printf("Titular:%s",ad->titular);
    printf("Telefono:%ld\n",ad->telefono );
    printf("Contenido:%s",ad->contenido );
    printf("Fecha:%d/",ad->fecha.dia); printf("%s/",meses[ad->fecha.mes-1]); printf("%d\n",ad->fecha.year );
}


void display() {

  FILE *flujo=NULL;
  ADVERT registro;
  int cont=1;

  flujo=fopen("data.dat","rb");

  if (flujo!=NULL) {
//utilizar la fun print
    while (fread(&registro,sizeof(ADVERT),1,flujo)>0) {
      printf("--------------------------------\n" );
      printf("\t Registro No. %d\n",cont );
      print(&registro);
      cont++;
    /*  printf("--------------------------------\n" );
      printf("\n\t Registro No. %d\n",cont );
      printf("ID: %d\n",registro.id );
      printf("Clase:%s\n",registro.clase);
      printf("Titular:%s",registro.titular );
      printf("Telefono:%ld\n",registro.telefono );
      printf("Contenido:%s",registro.contenido );
      printf("Fecha:%d/%s/%d\n",registro.fecha.dia,meses[(registro.fecha.mes)-1],registro.fecha.year );

      */
    }
    fseek(stdin,0,SEEK_END);//Limpia buffer
    getchar();
    fclose(flujo);
  }
  else{
    printf("ERROR..!\n" );
fseek(stdin,0,SEEK_END);
getchar();
}
}

void delete() {
  FILE *orig,*copy;
  int ban;
  ADVERT aux;
  char key[SIZE];

  orig=fopen("data.dat","rb");
  copy=fopen("temporal.dat","wb");

  if (orig==NULL || copy==NULL) {
    printf("%s\n","No se pudo completar la operacion" );
  }
  else{
    printf("%s","Numero de anuncio que desea cancelar:" );
    while(getchar()!='\n');//Limpia buffer
    setbuf(stdin,NULL);
    fgets(key,SIZE,stdin);
    ban=search(key);
    if (ban!=-1) {
        while (fread(&aux,sizeof(ADVERT),1,orig)>0) {
          if (atoi(key)!=aux.id) {
            fwrite(&aux,sizeof(ADVERT),1,copy);
          }
        }
        fclose(orig);
        fclose(copy);
        remove("data.dat");
        rename("temporal.dat","data.dat");
        printf("\n%s\n","Deleted!");
        while(getchar()!='\n');//Limpia buffer
        getchar();
    }
    else{
    printf("%s\n","No se encontro!" );
    while(getchar()!='\n');//Limpia buffer
    getchar();
      }
  }

}


int search(char key[]){
  FILE* flujo=NULL;
  ADVERT registro;
  int cont=0;

  flujo=fopen("data.dat","rb");
  if (flujo!=NULL) {
    while (fread(&registro,sizeof(ADVERT),1,flujo)>0) {
        cont++;
        if ((atoi(key))==registro.id) {
          fclose(flujo);
          return cont;
        }
    }
  }
  return -1;
}

void editar(){
  int ban,opc;
  char key[SIZE],*clases[]={"Venta varios","Autos","Mascota","Empleo","Renta","Traspaso"};
  ADVERT registro;
  FILE *flujo;

  printf("Numero de anuncio:");
  while(getchar()!='\n');//Espera a que presione enter.
  fgets(key,SIZE,stdin);
  ban=search(key);

  if (ban!=-1) {
  flujo=fopen("data.dat","rb+");
  if(flujo!=NULL){
    fseek(flujo,(ban-1)*sizeof(ADVERT),SEEK_SET);
    fread(&registro,sizeof(ADVERT),1,flujo);

    opc=menu_editar(); //despliega menu con campos a editar.
      switch (opc) {
          case 1:
            printf("Seleccione la nueva categoria:" );
            setbuf(stdin,NULL);
            strcpy(registro.clase,clases[(categoria())-1]);
              break;

          case 2:
              printf("Ingrese el nuevo nombre:");
              setbuf(stdin,NULL);
              fgets(registro.titular,SIZE,stdin);
              break;

          case 3:
            printf("Numero de telefono:");
            setbuf(stdin,NULL);
            scanf("%ld",&registro.telefono);
              break;

          case 4:
            printf("Ingrese nuevo contenido:" );
            setbuf(stdin,NULL);
            fgets(registro.contenido,SIZE,stdin);
            break;

          case 5:
            printf("Digite la nueva fecha(dd/mm/yyyy): " );
            setbuf(stdin,NULL);
            scanf("%d%d%d",&registro.fecha.dia,&registro.fecha.mes,&registro.fecha.year);
            break;

          case 6:
          printf("Seleccione la nueva categoria:" );
          setbuf(stdin,NULL);
          strcpy(registro.clase,clases[(categoria())-1]);
          printf("Ingrese el nuevo nombre:");
          setbuf(stdin,NULL);
          fgets(registro.titular,SIZE,stdin);
          printf("Numero de telefono:");
          setbuf(stdin,NULL);
          scanf("%ld",&registro.telefono);
          printf("Ingrese nuevo contenido:" );
          setbuf(stdin,NULL);
          fgets(registro.contenido,SIZE,stdin);
          printf("Digite la nueva fecha(dd/mm/yyyy): " );
          scanf("%d%d%d",&registro.fecha.dia,&registro.fecha.mes,&registro.fecha.year);

          break;

            }
          fseek(flujo,(ban-1)*sizeof(ADVERT),SEEK_SET);
          fwrite(&registro,sizeof(ADVERT),1,flujo);
          fclose(flujo);
        }
        else{
          printf("ERROR al abrir archivo!\n");
          while(getchar()!='\n');
        }
      }
      else{
        printf("ERROR 404! NOT FOUND!\n" );
        while(getchar()!='\n');
      }

    }



void search_cate(char key[],const int n){
  FILE* flujo=NULL;
  ADVERT registro;
  int cont=0,con2=0;//cont es la poscision en que se encuentra el registtro(no. de reg), con2 es par saber si se encontro o no el registro

  flujo=fopen("data.dat","rb");
  if (flujo!=NULL) {
    while (fread(&registro,sizeof(ADVERT),1,flujo)>0) {
        cont++;
        switch (n) {
          case 4:
          if (!strcasecmp(key,registro.clase)) {
            con2++;
            printf("--------------------------------------\n");
            printf("\tRegistro No.%d\n",cont );
            print(&registro);
          }
          break;

          case 5:
          if (!strcasecmp(key,registro.titular)) {
            con2++;
            printf("--------------------------------------\n");
            printf("\tRegistro No.%d\n",cont );
            print(&registro);
          }
          break;
        }

    }
    if (con2==0) {
      printf("No hay registros!\n" );
    }
  }
fclose(flujo);
if (n==4) {
  while(getchar()!='\n');
  getchar();
}
else{
  getchar();
}
}

void swap( void** a, void**b){
	ADVERT *aux;

  aux=*(ADVERT**)a;
  *(ADVERT**)a=*(ADVERT**)b;
  *(ADVERT**)b=aux;
}

void bubbleSort(void **array, int n, int (*cmp)( void**a, void**b)){
    int i,j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(cmp(array+i, array+j) > 0)
                swap(array+i, array+j);
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

//Ordena los datos en memoria
void ordena(int (*comparar)(void **a,void **b)){
ADVERT **array=NULL;
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


void backup() {
  FILE *flujo,*destino;
  ADVERT aux;

  flujo=fopen("data.dat","rb");
  destino=fopen("backup.csv","w");

if (!flujo || !destino)
    printf("%s\n","ERROR!!" );
else
  while(fread(&aux,sizeof(ADVERT),1,flujo)>0){
  limpia(&aux);
    fprintf(destino,"%d,%s,",aux.id,aux.clase);
    fputs(aux.titular,destino);
    fprintf(destino,",%ld,",aux.telefono);
    fputs(aux.contenido,destino);
    fprintf(destino,",%d/%d/%d\n",aux.fecha.dia,aux.fecha.mes,aux.fecha.year);
  }



fclose(flujo);
fclose(destino);

printf("\n\nDONE..!\n");
fseek(stdin,0,SEEK_END);
getchar();
}

//Ordena los datos en memoria y los guarda en un archivo.
void guarda_orden_nombre(){
  int cont=0;
  ADVERT **array;
  FILE *destino=NULL;

cont=crea_array_ptr(&array);
bubbleSort(array,cont,compara_nombre);

destino=fopen("temporal.dat","wb");

if (!destino)
    printf("ERROR!!!!\n");

  else{
    for (int i = 0; i < cont; ++i)
      fwrite(*(array+i),sizeof(ADVERT),1,destino);

        fclose(destino);
        remove("data.dat");
        rename("temporal.dat","data.dat");
        display();
        printf("\n\nDONE..!\n");
        fseek(stdin,0,SEEK_END);
        getchar();
  }


}

//Fun. que elimina el salto de linea guardado al obtener el los  datos por teclado.
void limpia(ADVERT *a) {
int i;

  for ( i = 0; a->titular[i]!='\0' ; i++) {
      if (a->titular[i]=='\n') {
        a->titular[i]='\0';
        break;
      }
  }

    for ( i = 0; a->contenido[i]!='\0' ; i++) {
        if (a->contenido[i]=='\n') {
          a->contenido[i]='\0';
          break;
        }

}


}


void anuncios_en_fecha(){

ADVERT aux;
FILE *flujo=NULL;
int date,date2,cont=1; //date2 es auxiliar; se guarda la fecha de la estructura en cada iteracion.

time_t t=time(NULL);
struct tm fecha=*localtime(&t);
date=((fecha.tm_year+1900)*10000 )+ ((fecha.tm_mon+1)*100)+(fecha.tm_mday);

flujo=fopen("data.dat","rb");

if (!flujo){
      printf("\n\nERROR..!\n");
      fseek(stdin,0,SEEK_END);
      getchar();
}
else{
    while (fread(&aux,sizeof(ADVERT),1,flujo)>0) {
        date2=(aux.fecha.year*10000)+(aux.fecha.mes*100)+(aux.fecha.dia);
        if (date2<=date){
        printf("--------------------------------\n" );
        printf("\t Registro No. %d\n",cont );
        print(&aux);
        }
        cont++;
    }


  }
fclose(flujo);

getchar();
}
/** FIN **/
