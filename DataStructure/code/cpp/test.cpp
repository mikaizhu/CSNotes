#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    s = "hello world";
    s[0] = 'H';
    cout << s << endl;
    for (string::iterator it=s.begin() + 1; it != s.end(); it++)
        cout << *it << endl;
}

