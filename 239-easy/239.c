#include <stdio.h>

int main() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    while (num != 1) {
        if (num % 3 == 0) {
            printf("%d 0\n", num);
            num /= 3;
        } else if (num % 3 == 1) {
            printf("%d -1\n", num);
            num--;
            num /= 3;
        } else if (num % 3 == 2) {
            printf("%d 1\n", num);
            num++;
            num /= 3;
        }
    }
    printf("1\n");
}
