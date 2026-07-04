#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int size, compare;
    scanf("%d %d", &size, &compare);

    vector<int> vec(size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &vec[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (vec[i] < compare)
        {
            printf("%d ", vec[i]);
        }
    }

    return 0;
}