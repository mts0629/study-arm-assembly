#include <stdio.h>

int addvalues(int a, int b);

int add6values(int a, int b, int c, int d, int e, int f);

int main(void) {
    int a = 1, b = 2;
    printf("1 + 2 = %d\n", addvalues(a, b)); // = 3

    int c = 3, d = 4, e = 5, f = 6;
    printf("(sum of 1 to 6) = %d\n", add6values(a, b, c, d, e, f)); // = 21

    return 0;
}
