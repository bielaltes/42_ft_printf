
#include "ft_printf.h"

int ft_printstr(t_flags flags, char* str, int *error)
{
    int aux;
    int i;

    if (flags.content)
        i = 0;
    i = 0;
    if (!str)
		return (ft_printstr(flags, "(null)", error));
    while (str[i] != '\0' && aux != -1)
    {
        aux = write(1, &str[i], 1);
        if (aux == -1)
            *error = 1;
        ++i;
    }
    return (i);
}

