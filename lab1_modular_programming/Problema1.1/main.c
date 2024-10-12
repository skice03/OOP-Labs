#include <stdio.h>
#include "temperature_converter.h"

int main()
{
    float value; char type;
    
    printf("Enter C for Celsius or F for Fahrenheit: \n");
    scanf("%c", &type);
    printf("Enter the value that will be converted: \n");
    scanf("%f", &value);
    printf("The converted value is: %f", degree_converter(value, type));
    
    return 0;
}
