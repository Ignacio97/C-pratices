#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib8.h"

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
//  printf("[7]Mostrar todos los registro en la fecha actual.\n");
//  printf("[8]Ordenar por responsable.\n");
//  printf("[9]Generar respaldo.\n");
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
  printf("Responsable:");       fgets(ad->titular,SIZE,stdin);
  printf("Telefono:");          scanf("%ld",&ad->telefono);
  setbuf(stdin,NULL); //Limpia el buffer de entrada.
  printf("Contenido:");          fgets(ad->contenido,SIZE,stdin);
  printf("Fecha (dd/mm/yyyy):");   scanf("%d%d%d",&ad->fecha.dia,&ad->fecha.mes,&ad->fecha.year);

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
  fclose(file);
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
  int cont=0,con2=0;

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

/*
void backup() {
  FILE *flujo,*destino;
  ADVERT aux;

  flujo=fopen("data,dat","r");
  destino=fopen("backup.txt","w");

if (!flujo || !destino) {

    printf("%s\n","ERROR!!" );
}

else{
  while (fread(&aux,sizeof(ADVERT),1,flujo)>0) {


  }

}
}

*/
/** FIN **/
