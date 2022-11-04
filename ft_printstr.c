
#include "libprintf.h"

int ft_printstr(t_flags flags, char* str, int *error)
{
    int aux;
    int i;

    i = 0;
    while (str[i] != '\0' and aux != -1)
    {
        aux = write(1, &c, 1);
        if (aux = -1)
            *error = 1;
        ++i;
    }
    return (i);
}

