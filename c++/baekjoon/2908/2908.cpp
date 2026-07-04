#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    char A[4];
    char B[4];
    char *answer;

    scanf("%s %s", A, B);

    swap(A[0], A[2]);
    swap(B[0], B[2]);

    answer = A;
    for (int i = 0; i < 3; i++)
    {
        if (A[i] > B[i])
        {
            break;
        }
        else if (A[i] < B[i])
        {
            answer = B;
            break;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%c", answer[i]);
    }

    return 0;
}
