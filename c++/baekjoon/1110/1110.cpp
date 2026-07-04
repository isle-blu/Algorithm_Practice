#include <stdio.h>

int cycle(int num)
{
    int temp;

    if (num < 10)
        temp = num;
    else
        temp = num / 10 + num % 10;
    num = (num % 10 * 10) + temp % 10;

    return num;
}

int main()
{
    int num, temp, count;
    scanf("%d", &num);
    count = 0;

    temp = num;
    do
    {
        temp = cycle(temp);
        count++;
    } while (num != temp);

    printf("%d\n", count);

    return 0;
}