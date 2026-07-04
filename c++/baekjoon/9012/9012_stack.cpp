#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    int T;
    char bracket[51];
    bool TF;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%s", bracket);

        stack<char> VPS = {};
        TF = true;

        int j = 0;
        while (true)
        {
            if (bracket[j] == '\0')
            {
                if (VPS.empty())
                {
                    break;
                }
                else
                {
                    TF = false;
                    break;
                }
            }
            else if (bracket[j] == '(')
            {
                VPS.push('(');
            }
            else if (bracket[j] == ')')
            {
                if (VPS.empty())
                {
                    TF = false;
                    break;
                }
                else
                {
                    VPS.pop();
                }
            }

            j++;
        }

        printf("%s", TF ? "YES\n" : "NO\n");
    }
}