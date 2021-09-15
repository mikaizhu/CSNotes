#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0)
        {
            if (res > INT_MAX / 10 || res < INT_MIN / 10) // 主要判断res是否过界
                // 为什么要除以10 呢？ 因为下方会乘以10，再加上一个数，肯定越界了。
                return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(-2147483412) << endl; 
}
