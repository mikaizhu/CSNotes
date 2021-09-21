#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int mid = (left + right) / 2;
        float divid;
        while (left <= right)
        {
            divid = x / mid;
            if ((int)divid == mid)
                break;
            if (divid > mid)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
        }
        return mid;
    }
};


int main()
{
    Solution s;
    cout << s.mySqrt(1);
}
