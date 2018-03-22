
#include <stdio.h>
#include "lib13.h"

int main()
{
    int num;
    char mensaje[]="hola";
    char clave='z';

    num=togglebit(19,5);
    printf("\n%d\n",num);

    display(300);

    num= introtright(32,4);
    printf("\n%d\n",num);
    num= introtleft(38,2);
    printf("\n%d\n",num);
    num=byterotright(41,4);
    printf("\n%d\n",num);
    num=byterotleft(111,2);
    printf("\n%d\n",num);
    num=getbyte(111,5);
    printf("\n%d\n",num);
    encrypt(&mensaje[0],clave);
    printf("\n%s",mensaje);
    encrypt(&mensaje[0],clave);
    printf("\n%s",mensaje);


    return 0;
}
