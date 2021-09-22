class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res; // 存放结果
        unordered_set<int> temp(nums1.begin(), nums1.end()); // 将vector转换成set
        for (int num : nums2)
        {
            if (temp.find(num) != nums2.end())
                res.insert(num);
        }
        return vector<int>(res.begin(), res.end());
    }
};
