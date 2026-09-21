/* Student: Kyle Netterville */
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 55; i++) {
        if (i % 11 == 10) {
            putchar('\n');
        } else if (i % 2 == 0) {
            putchar(' ');
        } else {
            putchar('X');
        }
    }
    return 0;
}