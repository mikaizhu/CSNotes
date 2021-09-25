#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for (char c : s)
        {
            if (c == ' ') res += "%20";
            else res += c;
        }
        return res;
    }
};
*/

class Solution {
public:
    string replaceSpace(string s) {
        // 统计有多少个空格
        int count = 0;
        for (char c : s)
            if (c == ' ') count++;
        if (count == 0) return s;
        int left = s.size() - 1;
        s.resize(s.size() + 2*count); 
        // 2是多出来的字符长度, risize后，末尾都是空字符
        // 然后从右边开始遍历, 遇到空格就向右边移动，所以从右边开始遍历
        int right = s.size() - 1;
        while (left >= 0)
        {
            if (s[left] != ' ') 
            {
                s[right] = s[left];
                right--;
            }
            else
            {
                s[right] = '0';
                s[right-1] = '2';
                s[right-2] = '%';
                right -= 3;
            }
            left--;
        }
        return s;
    }
};

int main()
{
    Solution so;
    string s = "a bc";
    s = so.replaceSpace(s);
    for (char c : s) cout << c;
}
