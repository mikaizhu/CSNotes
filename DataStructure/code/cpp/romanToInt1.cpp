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
        };
        int res = 0;
        for (string::iterator cur = s.begin(); cur != s.end(); cur++)
        {
            if (cur + 1 != s.end() && hashmap[*cur] < hashmap[*(cur+1)])
                res -= hashmap[*cur];
            else
                res += hashmap[*cur];
        }
        return res;
    }
};

