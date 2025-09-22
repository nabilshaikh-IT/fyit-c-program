#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100], part[100];
    int start, length, i;

    printf("Enter a string: ");
    gets(str);  // or use fgets(str, sizeof(str), stdin);

    printf("Enter starting position (o-based index) : ");
    scanf("&d", &start);

    printf("Enter number of characters to extract: ");
    scanf("&d", &length);

    for (i = 0; i < length; i++) {
        part[i] = str[start + i];
    }
    part[i] = '\0';

    printf("Extracted part: &s\n", part);

    return 0;
}
