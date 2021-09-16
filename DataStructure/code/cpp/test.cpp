#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static void print();
void print(vector<vector<int> > &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (vector<int>::iterator it = v[i].begin(); it != v[i].end(); it++)
            cout << *it << ' ';
    cout << endl;
    }
}

int main()
{
    vector<vector<int> > v;
    v = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3},
    };

    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
    //print(v);
}

