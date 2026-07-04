#include <stdio.h>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> ans;

void merge(int front, int mid, int back)
{
    int f = front;
    int b = mid + 1;

    int i = front;

    while (f <= mid && b <= back)
    {
        if (vec[f] >= vec[b])
        {
            ans[i] = vec[f];
            f++;
        }
        else
        {
            ans[i] = vec[b];
            b++;
        }
        i++;
    }

    for (; f <= mid; f++)
    {
        ans[i] = vec[f];
        i++;
    }

    for (; b <= back; b++)
    {
        ans[i] = vec[b];
        i++;
    }

    for (int j = front; j <= back; j++)
    {
        vec[j] = ans[j];
    }
}

void mergeSort(int front, int back)
{
    if (front < back)
    {
        int mid = (front + back) / 2;
        mergeSort(front, mid);
        mergeSort(mid + 1, back);
        merge(front, mid, back);
    }
}

int main()
{
    int num;

    while (scanf("%1d", &num) != EOF)
    {
        vec.push_back(num);
    }

    int size = vec.size();

    ans.resize(size);

    mergeSort(0, size - 1);

    for (int n : vec)
    {
        printf("%d", n);
    }
}