#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int _2k = 2 * k ;
        int loop = s.size() / _2k + 1;
        for (int i = 0; i < loop; i++)
        {
            int left = i * _2k, right;
            left + k - 1 <= (s.size() - 1) ? right = left + k - 1 : right = s.size() - 1;
            reverse(s.begin() + left, s.begin() + right + 1);
            cout << left << " " << right << endl;
            /*
            while (left <= right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            */
        }
        return s;
    }
};


int main()
{
    string s = "hbcdefg";
    Solution so;
    s = so.reverseStr(s, 2);
    for (char c : s)
        cout << c << " " ;
}
