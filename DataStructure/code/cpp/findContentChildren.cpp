#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (count >= g.size())
                break;
            if (g[count] > s[i])
                g[count] = g[count] - s[i];
            else
                count++;
        }
        return count;
    }
    int findContentChildren1(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int children = 0, cookie = 0;
        while (children < g.size() && cookie < s.size())
        {
            if (s[cookie] < g[children])
                cookie++;
            children++;
        }
        return children;
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {6, 2};
    vector<int> v2 = {1, 2, 3};
    int res = s.findContentChildren(v1, v2);
    cout << res << endl;
}
