#include "temperature_converter.h"

float degree_converter(float value, char type)
{
    return type == 'C' ? ((9.0 / 5.0) * value + 32) : (5.0 / 9.0) * (value - 32);
}
