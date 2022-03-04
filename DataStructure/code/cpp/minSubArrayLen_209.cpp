// method 1
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int ans = INT_MAX;
       int sum = 0;
       for (int i = 0, j = 0; j < nums.size();j++) {
           sum = sum + nums[j];
           while (sum >= target) {
               ans = j - i + 1 < ans ?  j - i + 1 : ans;
               sum = sum - nums[i];
               i++;
           }
       }
       return ans == INT_MAX ? 0 : ans;
    }

};

// method 2
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        if (sum(nums, 0, nums.size() - 1) < target) {
            return 0;
        }
        for ( int i = 0, j = 0; j < nums.size();) {
            if (sum(nums, i, j) >= target) {
                ans = j - i + 1 < ans ? j - i + 1 : ans;
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
    int sum(vector<int>& nums, int i, int j) {
        int ans = 0;
        for (; i <= j; i++) {
            ans = ans + nums[i];
        }
        return ans;
    }
};


