#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>


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
    vector<int> vec;
    vec.push_back(NULL);
    for (int i : vec) {
        cout << i << endl;
    }
}
