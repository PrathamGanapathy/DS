#include <stdio.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

void main()
{
    int a,b;
    printf("Enter values for a and b ");
    scanf("%d%d",&a,&b);
    printf("Before swap: a = %d   b = %d\n",a,b);
    swap(&a , &b);
    printf("After swap: a = %d   b = %d",a,b);
}
