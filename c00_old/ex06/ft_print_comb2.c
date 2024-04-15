#include <unistd.h>
void    ft_print_comb2(void)
{
    char    res[5];
    res[2] = ' ';
    int temp, a = 0, b;
    while (a < 99)
    {
        temp = a / 10;
        res[0] = temp + 48;
        res[1] = (a - temp*10) + 48;
        b = a+1;
        while (b < 100)
        {
            temp = b / 10;
            res[3] = temp + 48;
            res[4] = (b - temp*10) + 48;
            write(1, res, 5);
            if((a==98) && (b==99)) return;
            else write(1, ", ", 2);
            b++;
        }
        a++;
    }
}