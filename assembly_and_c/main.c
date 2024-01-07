#include <stdio.h>

int addvalues(int a, int b);

int main(void) {
    int a = 1, b = 2;
    int c = addvalues(a, b);

    printf("c = %d\n", c);

    return 0;
}
