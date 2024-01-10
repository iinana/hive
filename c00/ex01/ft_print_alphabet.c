#include <unistd.h>
void    ft_print_alphabet(void)
{
    char    c = 'a';
    while (c < 123)
    {
        write(1, &c, 1);
        c++;
    }
}