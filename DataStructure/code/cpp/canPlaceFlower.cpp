#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);
        int count = 1;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (n == 0)
                return true;
            if (flowerbed[i] == 0)
                count++;
            else
                count = 0;
            if (count == 3)
            {
                n--;
                count = 1;
            }
        }
        cout << "n: " << n << endl;
        return n == 0;
    }
};

int main()
{
    Solution s;
    //vector<int> v = {1, 0, 0, 0, 0, 1};
    vector<int> v = {0, 0, 0, 0, 0};
    s.canPlaceFlowers(v, 3);

}
