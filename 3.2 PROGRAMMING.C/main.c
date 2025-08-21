#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i = 1;
    unsigned long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial is not defiend for negative number.");
    else {
         while (i <=num) {
             fact *= i;
             i++;
         }
         printf("Factorial of %d = %llu", num, fact);
    }

    return 0;


}
