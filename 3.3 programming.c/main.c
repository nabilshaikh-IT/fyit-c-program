#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a = 0, b = 1, next, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <=0)
        printf("Please enter a positive number.");
    else if (n ==1)
         printf("%d", a);
    else {
        printf("Fibonacci series: %d %d ", a, b);
        for (i = 3; i <= n; i++) {
             next = a + b;
             printf("%d ", next);
             a = b;
             b = next;
        }
    }

    return 0;

}
