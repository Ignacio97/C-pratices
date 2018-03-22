#include <stdio.h>

void swap(int *aptr,int* bptr);

int main() {
  int a=4,b=99;


printf("a=%d\n",a );
printf("b=%d\n",b );

swap(&a,&b);

printf("a=%d\n",a );
printf("b=%d\n",b );

  return 0;
}

void swap(int *aptr,int* bptr) {
  int aux;
  aux=*aptr;
  *aptr=*bptr;
  *bptr=aux;
}
