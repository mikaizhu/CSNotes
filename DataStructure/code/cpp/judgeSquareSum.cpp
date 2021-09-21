#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = (int)sqrt(c);
        int sum;
        while (left < right)
        {
            cout << "right: " << right << endl;
            sum = left * left + right * right;
            if (sum < c)
                ++left;
            else if (sum > c)
                --right;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.judgeSquareSum(2);
}
