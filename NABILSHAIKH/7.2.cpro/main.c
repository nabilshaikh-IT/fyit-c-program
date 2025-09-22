#include <stdio.h>

void swapReference(int *X,int *Y) {
     int temp;
     temp = *X;
     *X = *Y;
     *Y = temp;
     printf("Inside swapReference - X: %d, Y: %d\n", *X, *Y);
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Before swapReference - a: %d, b: %d\n", a, b);
    swapReference(&a, &b);
    printf("After swapReference - a: %d, b: %d|n", a, b);

    return 0;
}
