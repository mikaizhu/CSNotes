#include <iostream>
#include <algorithm>
#include <vector>
#include<numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // 先初始化所有的为1
        vector<int> res(ratings.size(), 1);

        // 从左往右遍历
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i-1])
                res[i] = res[i-1] + 1;
        }

        // 从右往左计算
        for (int i = ratings.size() - 1; i > 0; i--)
        {
            if (res[i-1] <= res[i] && ratings[i-1] > ratings[i])
            {
                res[i-1] = res[i] + 1;
            }
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 0, 2};
}
