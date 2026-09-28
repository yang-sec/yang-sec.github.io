/*
 * fibo.c
 *
 * Usage: ./fibo n
 *
 * Converts the command-line argument n to an int using atoi(),
 * then prints every Fibonacci number that is <= n.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    int a = 0, b = 1;
    while (a <= n) {
        printf("%d\n", a);
        int next = a + b;
        a = b;
        b = next;
    }

    return 0;
}
