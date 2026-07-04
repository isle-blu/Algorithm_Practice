#include <stdio.h>

int main()
{
    int num1, num2, temp;

    scanf("%d\n %d", &num1, &num2);

    temp = num2;
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", num1 * (temp % 10));
        temp /= 10;
    }

    printf("%d\n", num1 * num2);

    return 0;
}