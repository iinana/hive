#include <unistd.h>

void ft_print_comb(void) {
    char link[2] = ", ";
    char chari, charj, chark;

    for (int i = 0; i <= 7; i++) {
        chari = i+48;
        for (int j = (i+1); j  <= 8; j++) {
            charj = j + 48; 
            for (int k = (j+1); k <= 9; k++) {
                chark = k + 48;

                write(1, &chari, 1);
                write(1, &charj, 1);
                write(1, &chark, 1);

                if ((i==7) && (j == 8) && (k==9)) return;
                else write(1, link, 2);
            }
        }
    }
}