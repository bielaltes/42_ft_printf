#include "libprintf.h"

int ft_print%(int *error)
{
    int aux;
    aux = write(1, "%", 1);
    if (aux = -1)
        *error = 1;
    return (1);
}
