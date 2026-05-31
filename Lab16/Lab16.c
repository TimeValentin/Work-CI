#include <stdio.h>
#include <stdlib.h>

/*
	
*/

int countlong(long num) {
    int count;
    unsigned long mask;

    count = 0;
    mask = 1UL << (sizeof(long) * 8 - 1);
    while (mask) {
        if (num & mask)
            count++;
        mask >>= 1;
    }
    return count;
}

int countdouble(double num) {
    unsigned char *bytes;
    int i, j, count;
    unsigned char byte;

    bytes = (unsigned char *)&num;
    count = 0;
    for (i = 0; i < sizeof(double); i++) {
        byte = bytes[i];
        for (j = 0; j < 8; j++) {
            if (byte & 1)
                count++;
            byte >>= 1;
        }
    }
    return count;
}

int main() {
    long long_num;
    double double_num;

    printf("enter long integer: ");
    scanf("%ld", &long_num);
    printf("enter double: ");
    scanf("%lf", &double_num);

    printf("%d\n", countlong(long_num));
    printf("%d\n", countdouble(double_num));

    return 0;
}
