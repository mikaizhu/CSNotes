#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if (nums[right] != target)
            return res;
        res[0] = right;
        right = nums.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target) // 注意这里和上面就是没有等号
                right = mid;
            else
                left = mid + 1;
        }
        res[1] = left-1;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v = {5, 7, 7, 8, 8, 10};
    s.searchRange(v, 8);
}
