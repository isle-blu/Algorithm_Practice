#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;

void calculate(vector<int> &sequence, vector<int> &oper, int now, int count, int result)
{
    if (count <= 0)
    {
        ans.push_back(result);
        return;
    }

    vector<int> tmpOper = oper;
    if (tmpOper[0] > 0)
    {
        tmpOper[0]--;
        calculate(sequence, tmpOper, now + 1, count - 1, result + sequence[now]);
    }

    tmpOper = oper;
    if (tmpOper[1] > 0)
    {
        tmpOper[1]--;
        calculate(sequence, tmpOper, now + 1, count - 1, result - sequence[now]);
    }

    tmpOper = oper;
    if (tmpOper[2] > 0)
    {
        tmpOper[2]--;
        calculate(sequence, tmpOper, now + 1, count - 1, result * sequence[now]);
    }

    tmpOper = oper;
    if (tmpOper[3] > 0)
    {
        tmpOper[3]--;
        calculate(sequence, tmpOper, now + 1, count - 1, result / sequence[now]);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> sequence(N);
    vector<int> oper(4, 0);

    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        sequence[i] = temp;
    }

    for (int i = 0; i < 4; i++)
    {

        scanf("%d", &temp);
        oper[i] = temp;
    }

    calculate(sequence, oper, 1, N - 1, sequence[0]);

    sort(ans.begin(), ans.end());

    printf("%d\n%d", ans.back(), ans.front());

    return 0;
}