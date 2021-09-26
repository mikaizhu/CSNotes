#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

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
    string s = "abc";
    string v(s.begin(), s.begin()+1);
    for (char c : v)
        cout << c;
    cout << endl;
}

