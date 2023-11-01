#include <stdio.h>

int addvalues(int a, int b) {
    int c;
    c = a + b;
    return c;
}

int main(void) {
    int val = addvalues(1, 2);
    printf("addvalues = %d\n", val);
    return 0;
}
