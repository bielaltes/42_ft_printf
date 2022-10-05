
#include "libprintf.h"

int ft_printchar(t_flags flags, int c, int *error)
{
    int aux;
    aux = write(1, &c, 1);
    if (aux = -1)
        *error = 1;
    return (1);
}
