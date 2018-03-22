#include <stdio.h>
#include <stdlib.h>

struct header{
   char id[2];///ID field (42h,4Dh)
   char size[4];///size of the BMP file
   char unused1[2];///Application spec
   char unused2[2];///Application spec
   char offset[4];///Offset where the pixel array can be found
   char number_bytes[4];///Number of bytes in the DIB header
   char width[4];///Height of the bitmap in pixels
   char height[4];///h of the bitmap in pixels
   char number_color[2];///Number of colors planes being used
   char nbits_pixel[2];/// Numbers of bits per pixel
   char rgb[4];///BI_RGB no pixel array compression used
   char sizeraw_bitmap[4];///Size of the raw bitmap dat
   char horcolor_image[4];///Print resolution of the image
   char vercolor_image[4];///Print resolution of the image
   char number_colors[4];///Number of colors in the palette
   char all_colors[4];///0 means all colors
};

int main(){
   char image_name[30];///Espacio reservado de caracteres para hacer la busqueda de la imagen
   FILE *image;
   int id,image_size,width,height,pix,aux;
   char first,second;

   printf("Ingrese el nombre del archivo:");
   scanf("%s",image_name);


   image = fopen(image_name,"rb");
   if(image==NULL){
    printf("***ARCHIVO NO ENCONTRADO***");
   }///fin del if
   else{
        first=fgetc(image);
        second=fgetc(image);
        if(first=='B' && second=='M'){
            printf("ID: %xh-%xh\n",first,second);
            fseek(image, 18, SEEK_SET);    /* Posici�n 18: ancho */
            fread(&width, 1, 4, image);
            printf("Ancho: %d pixels\n", width);
            fread(&height, 1, 4, image);     /* Siguiente dato: alto */
            printf("Alto: %d pixels\n", height);
            pix=width*height;
            image_size=(24*pix)/8;///Multiplicado x24 ya que rgb
            printf("size(bytes): %d\n",image_size);
            printf("size(KB): %d\n",image_size/1024);
            printf("size(MB): %d\n",image_size/2048);
        }
        else{
            printf("No se encontro!");
        }
   }///fin else

   fclose(image);
   return 0;

}

/*
1. Ilustre la(s) estructuras utilizadas en este ejercicio.

typedef struct{
    char ID[2];
    int size;
    int reserved;
    int offset;
    int DIBheader;
    int Width;
    int Height;
    short int numColor;
    short int numBits;
    int BI_RGB;
    int bitmapSize;
    int imgRes1;
    int imgRes2;
    int colors;
    int impColors;
}BMP;

2. ¿Por qué una estructura con los campos descritos en el encabezado no mide los 54
bytes calculados?
Porque el tamaño se calcula como un multiplo del tipo de dato mas grande de la estructura
en este caso al ser int su tamano es 4 por lo que el tamano de la estuctura sera 52 o 56.

3. ¿De qué forma se puede leer de forma correcta el archivo?
Leyendo por campos de bits.

4. ¿Qué soluciones se proponen para almacenar el encabezado en una estructura?
Usar un arreglo de tipo char para guardar los caracteres del encabezado.

5. Proponga un procedimiento para escribir en otro archivo el mismo encabezado
pero con ciertas modificaciones.
Usando fwrite con la estructura que declaramos y donde guardamos los datos de la otra imagen
y para modificarlo solo cambiamos los valores en la estructura.
*/
