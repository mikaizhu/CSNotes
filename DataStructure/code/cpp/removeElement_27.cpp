#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = 0;
        for (int i = 0; right < nums.size(); i++)
        {
            while (right < nums.size() && nums[right] == val) right++;
            if (right == nums.size()) return 0;
            nums[i] = nums[right];
            right++;
        }
        return 0;
    }
};

int main()
{
    vector<int> v = {3, 2, 2, 3};
    Solution so;
    so.removeElement(v, 3);
    for (int c : v)
        cout << c << " ";
    cout << endl;
}
