#include <unistd.h>
void    ft_print_numbers(void) 
{
    char    c = '0';
    while (c < 58) 
    {
        write(1, &c, 1);
        c++;
    }
}