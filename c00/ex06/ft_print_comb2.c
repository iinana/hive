#include <unistd.h>

void ft_print_comb2(void) {
    char a1, a2, b1, b2;
    int temp;

    for (int a = 0; a < 99; a++) {
        temp = a / 10;
        a1 = temp + 48;
        a2 = (a - temp*10) + 48;
        for (int b = (a+1); b < 100; b++) {
            temp = b / 10;
            b1 = temp + 48;
            b2 = (b - temp*10) + 48;

            write(1, &a1, 1);
            write(1, &a2, 1);
            write(1, " ", 1);
            write(1, &b1, 1);
            write(1, &b2, 1);

            if((a==98) && (b==99)) return;
            else write(1, ", ", 2);
        }
    }
}