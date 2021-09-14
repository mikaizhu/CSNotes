#include <iostream>
#include <unordered_map>

using namespace std;

void print(unordered_map<int, int> &m)
{
    for (unordered_map<int, int>::iterator it=m.begin(); it != m.end(); it++)
    {
        cout << "key: " << it->first << " " << "value: " << it->second << endl;
    }
}

int main()
{
    unordered_map<int, int> m = {
        {1, 2},
        {2, 3},
        {3, 4},
    };

    print(m);
}
