#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

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

/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        multimap<char> myMap1;
        multimap<char> myMap2;
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
            myMap1.insert(s[i]);
        for (int i = 0; i < t.size(); i++)
            myMap2.insert(t[i]);
        for (int i = 0; i < s.size(); i++)
            if (myMap1.count(s[i]) != myMap2.count(s[i]))
                return false;
        return true;
    }
};
*/
int main()
{
    //string s = "anagram";
    //string t = "nagaram";
    //Solution so;
    //cout << so.isAnagram(s, t) << endl;
    int l[10] = {0};
    for (int i = 0; i < 10; i++)
        cout << l[i] << " ";
    cout << endl;
    cout << 'a' << endl;
}
