#include <stdio.h>

int sequence(int fin, int now, int before1, int before2)
{
    if (fin == now)
    {
        return before2;
    }

    int temp = before1 + before2;
    before1 = before2;
    before2 = temp;

    return sequence(fin, ++now, before1, before2);
}

int main()
{
    int num, answer;
    scanf("%d", &num);

    answer = (num == 0) ? 0 : sequence(num, 1, 0, 1);
    printf("%d", answer);

    return 0;
}