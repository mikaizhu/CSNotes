#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int twoSearch(const vector<int>& nums, int left, int right, int target)
    {
        int mid;
        while (left < right)
            {
                mid = (left + right) / 2;
                if (nums[mid] ==  target)
                    return mid;
                else if (nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid;
            }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid;
        int res;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[left] < nums[mid]) // 说明左边部分有序
            {
                right = mid;
                res = twoSearch(nums, left, right, target);
                if (res != -1)
                    return mid;
                left = mid + 1;
            }
            else if (nums[right] > nums[mid])// 否则说明右边部分有序
            {
                left = mid;
                res = twoSearch(nums, left, right, target);
                if (res != -1)
                    return mid;
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 2, 2, 3, 2, 2, 2};
    cout << s.search(v, 3);
}
