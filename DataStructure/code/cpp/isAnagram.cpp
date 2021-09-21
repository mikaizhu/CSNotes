#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(string &s)
{
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
}


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        print(s);
        print(t);
        int i = 0;
        for (; i < s.size() && s[i] == t[i]; i++);
        if (i == s.size())
            return true;
        return false;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagaram";
    Solution so;
    cout << so.isAnagram(s, t) << endl;
    
}
