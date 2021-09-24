#include<iostream>
#include<vector>
#include<unistd.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res; // res初始化为空矩阵
        if (nums.size() < 3) return res; // 如果长度小于3，则返回空矩阵
        sort(nums.begin(), nums.end());
        // 初始化，为了避免和之前元素值相同, 所以初始化为原来减1
        for (int left = 0; left < nums.size() - 1; left++)
        {
            if (nums[left] > 0) return res;
            if (left > 0 && nums[left] == nums[left - 1]) // left去除重复
                continue;
            int mid = left + 1, right = nums.size() - 1;
            while (mid < right)
            {
                int sum = nums[left] + nums[mid] + nums[right];
                if (sum > 0)
                {
                    right--;
                    while (right > mid && nums[right] == nums[right + 1]) right--;
                }
                else if (sum < 0)
                {
                    mid++;
                    while (right > mid && nums[mid] == nums[mid - 1]) mid++;
                }
                else
                {
                    res.push_back({nums[left], nums[mid], nums[right]});
                    right--;
                    mid++;
                    while (right > mid && nums[right] == nums[right + 1]) right--;
                    while (right > mid && nums[mid] == nums[mid - 1]) mid++;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v;
    v = {-1, 0, 1, 0};
    Solution s;
    s.threeSum(v);
}
