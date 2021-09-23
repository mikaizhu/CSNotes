class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<int> sum1, sum2;
        int res = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                sum1.push_back(nums1[i] + nums2[j]);
                sum2.push_back(nums3[i] + nums4[j]);
            }
        }
        for (int i = 0; i < sum1.size(); i++)
        {
            for (int j = 0; j < sum2.size(); j++)
            {
                if (sum1[i] + sum2[j] == 0)
                    res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> count_map;
        int res;
        for (int a : nums1)
        {
            for (int b : nums2)
                count_map[a+b]++;
        }
        for (int a : nums3)
        {
            for (int b : nums4)
            {
                if (count_map.find(0-(a+b)) != count_map.end())
                        res+=count_map[0-(a+b)];
            }
        }
        return res;
    }
};

