class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (nums[left] != 0) left++;
        while (nums[right] == 0) right++;


    }
};
