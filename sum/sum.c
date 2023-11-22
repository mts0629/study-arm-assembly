#include <stdio.h>

int sum(int limit) {
    int i, total = 0;

    for (i = 0; i <= limit; i++) {
        total += i;
    }

    return total;
}

int main(void) {
    int val = 10;
    int retval = sum(val);

    printf("sum(%d) = %d\n", val, retval);

    return 0;
}
