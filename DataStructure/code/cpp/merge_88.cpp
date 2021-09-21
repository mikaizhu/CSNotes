#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int length_1 = nums1.size();
        for (int i = m; i < length_1; i++)
        {
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main()
{

}
