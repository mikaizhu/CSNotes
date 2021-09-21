#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isIncreasing(const vector<int>& nums, int start)
    {
        int pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == start)
                continue;
            if (nums[i] > pre)
                pre = nums[i];
            else
                return false;
        }
        return true;
    }

    bool canBeIncreasing(vector<int>& nums) {
        int len = nums.size();
        int i = 1;
        for (; i < len && nums[i-1] < nums[i]; i++);
        if (i == len)
            return true;
        else
            return isIncreasing(nums, i-1) || isIncreasing(nums, i);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 10, 5, 7};
    cout << s.canBeIncreasing(v);
}
