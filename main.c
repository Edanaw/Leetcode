#include <stdio.h>
#include <string.h>
#include "big.h"

// char *stdin_get_str(char *str);
// void BigNumberMul(char a[], char b[]);

int main()
{
    char a[220];
    char b[220];

    stdin_get_str(a);
    stdin_get_str(b);
    BigNumberMul(a, b);

    return 0;
}