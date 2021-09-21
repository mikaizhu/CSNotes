#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string s)
    {
        int left = 0, right = s.size() - 1;
        while (left <= right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right)
        {
            if (s[left] != s[right])
            {
                if (isPalindrome(s.substr(left, right - left)) || isPalindrome(s.substr(left + 1, right - left)))
                    return true;
                else
                    return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string st = "abca";
    cout << s.validPalindrome(st);
}
