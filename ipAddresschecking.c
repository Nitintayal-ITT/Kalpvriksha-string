#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    char str[20];

    printf("Enter an IP address: ");
    scanf("%s", str);

    int num = 0, dots = 0;
    char *ptr = str;

    if (str == NULL) {
        return 0;
    }

    while (*ptr != '\0') {
        if (*ptr == '.') {
            dots++;
            if (num < 0 || num > 255 || dots > 3) {
                return 0;
            }
            num = 0;
        } else if (isdigit(*ptr)) {
            num = num * 10 + (*ptr - '0');
        } else {
            return 0;
        }
        ptr++;
    }
    if (num < 0 || num > 255 || dots != 3) {
        printf("\n INValid IP");
    }
    else{
        printf("\n VALID");
    }
    return 0;
}