#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int> > &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
    

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){if (a[1] == b[1]) return a[0] < b[0]; else return a[1] < b[1];});
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){return a[0] < b[0];});
        print(points);
        int arrow_count = 1;
        int start = points[0][0], end = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (start <= points[i][0] && points[i][0] <= end)
            {
                points[i][0] > start ? start = points[i][0] : start = start;
                points[i][1] < end ? end = points[i][1] : end = end;
            }
            else
            {
                arrow_count++;
                start = points[i][0];
                end = points[i][1];
            }
        }
        return arrow_count;
    }
};

int main()
{
    /*
    vector<vector<int> > v = {
        {1, 2},
        {4, 5},
        {1, 5},
    };
    */
    vector<vector<int> > v = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    Solution s;
    cout << s.findMinArrowShots(v);
}
