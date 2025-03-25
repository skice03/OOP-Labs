#include <stdio.h>

#define DEBUG // pentru cerinta de la problema 1.3

#define USE_HEADER1 1
#if USE_HEADER1 == 1
#include "header1.h"
#else
#include "header2.h"
#endif

int main()
{
    int x, y;
    printf("Enter the values of X and Y: ");
    scanf("%d %d", &x, &y);
    printf("%d\n", f(x, y));

#ifdef DEBUG
    printf("Se foloseste modul debug");
#endif

    return 0;
}