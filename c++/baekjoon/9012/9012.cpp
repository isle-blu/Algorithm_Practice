#include <stdio.h>
using namespace std;

int main()
{
    char bracket[51];
    int num, stack;
    bool TF;

    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        scanf("%s", bracket);

        TF = true;
        stack = 0;
        int j = 0;
        while (true)
        {
            if (bracket[j] == '(')
            {
                stack++;
            }
            else if (bracket[j] == ')')
            {
                stack--;
                if (stack < 0)
                {
                    TF = false;
                    break;
                }
            }
            else
            {
                if (stack > 0)
                {
                    TF = false;
                }

                break;
            }
            j++;
        }

        printf(TF == true ? "YES\n" : "NO\n");
    }

    return 0;
}