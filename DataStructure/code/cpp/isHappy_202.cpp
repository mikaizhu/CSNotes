#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unistd.h>


using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> History;
        int happy;
        while (happy != 1)
        {
            while (n != 0)
            {
                int temp = n % 10;
                happy += temp * temp;
                n = n / 10;
            }
            n = happy;
            if (History.find(happy) != History.end())
                return false;
            History.insert(happy);
            cout << happy << endl;
            sleep(2);
        }
        return true;
    }
};

int main()
{
    Solution s;
    s.isHappy(19);
}
