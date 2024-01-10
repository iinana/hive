#include <unistd.h>
void    ft_print_comb(void) 
{
    char    res[3];
    int i = 0, j, k;
    while (i <= 7)
    {
        res[0] = i+48;
        j = i+1;
        while (j <= 8)
        {
            res[1] = j+48;
            k = j+1;
            while (k <= 9)
            {
                res[2] = k+48;
                write(1, res, 3);
                if ((i==7) && (j == 8) && (k==9)) return;
                else write(1, ", ", 2);
                k++;
            }
            j++;
        }
        i++;
    }
}