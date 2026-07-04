#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> tree;
    float count = 0;
    string input;

    while (getline(cin, input))
    {
        if (cin.eof())
        {
            break;
        }
        else if (tree.find(input) != tree.end())
        {
            tree[input]++;
        }
        else
        {
            tree.insert({input, 1});
        }
        count++;
    }

    cout << fixed;
    cout.precision(4);
    float ratio;
    for (auto i = tree.begin(); i != tree.end(); i++)
    {
        ratio = i->second / count * 100;
        cout << i->first << " " << ratio << endl;
    }

    return 0;
}
