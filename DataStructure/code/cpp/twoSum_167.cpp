#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        int temp;
        while (true)
        {
            temp = numbers[left] + numbers[right];
            if (temp == target)
                return {left + 1, right + 1};
            else if (temp > target)
                right--;
            else
                left++;
        }
    }
};

int main()
{

}
