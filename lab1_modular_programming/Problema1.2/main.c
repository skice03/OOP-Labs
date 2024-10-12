#include <stdio.h>
#define USE_HEADER1 1
#if USE_HEADER1==1
    #include "header1.h"
#else   
    #include "header2.h"
#endif


int main()
{
    int x, y;
    printf("Enter the values of X and Y: ");
    scanf("%d %d", &x, &y);
    printf("%d\n", f(x,y));

    return 0;
}