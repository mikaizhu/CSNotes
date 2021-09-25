#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include<unistd.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 排除重复的
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 跳过重复的
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
                    if (sum > target)
                    {
                        right--;
                        while (left < right && nums[right] == nums[right+1])
                            right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                        while (left < right && nums[left] == nums[left-1])
                            left++;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        right--;
                        left++;
                        while (left < right && nums[right] == nums[right+1])
                            right--;
                        while (left < right && nums[left] == nums[left-1])
                            left++;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {1, -2, -5, -4, -3, 3, 3, 5};
    Solution s;
    s.fourSum(v, -11);
}
