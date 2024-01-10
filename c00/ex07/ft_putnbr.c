#include <unistd.h>

void ft_putnbr(int nb) {
    int pow = 1;
    char res[11];
    int count = 0;
    int temp;
    if (nb < 0) {
        res[0] = '-';
        count++;
        nb = -nb;
    }

    while ((nb / pow) > 9) pow *= 10;

    while (pow > 0) {
        temp = nb / pow;
        nb -= temp * pow;
        res[count] = temp + 48;
        count++;
        pow /= 10;
    }

    write(1, res, count);
}