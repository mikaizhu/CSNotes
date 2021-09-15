#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashmap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
            {'Q', 0},
        };
        s += 'Q';
        int res = 0;
        string::iterator pre = s.begin();
        for (string::iterator cur = s.begin() + 1; cur != s.end(); cur++)
        {
            if (hashmap[*cur] > hashmap[*pre])
                res -= hashmap[*pre];
            else
                res += hashmap[*pre];
            pre = cur;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("III") << endl;
}
