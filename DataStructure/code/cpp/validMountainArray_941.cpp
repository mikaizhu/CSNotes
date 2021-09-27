class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() <= 2) return false;
        int left = 1, right = arr.size() - 2;
        int left_flag = 1, right_flag = 1;
        while (left < arr.size() && arr[left] > arr[left-1]) 
        {
            left++;
            left_flag = 0;
        }
        while (right >= 0 && arr[right] > arr[right+1]) 
        {
            right--;
            right_flag = 0;
        }
        if (right_flag || left_flag) return false;
        if (left - 1 == right + 1) return true;
        return false;
    }
};
