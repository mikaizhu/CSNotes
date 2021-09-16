#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int> > &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (vector<int>::iterator it = v[i].begin(); it != v[i].end(); it++)
            cout << *it << ' ';
    cout << endl;
    }
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
        int remove_count = 0;
        if (intervals.size() < 2)
            return 0;
        //vector<int> pre_v = intervals[0];
        int pre_v = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < pre_v)
                remove_count++;
                //cout << intervals[i][0] << ' ' << intervals[i][1] << endl;
            else
                pre_v = intervals[i][1];
        }
        return remove_count;
    }
};

int main()
{
    vector<vector<int> > v;
    v = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3},
    };
    Solution s;
    cout << s.eraseOverlapIntervals(v);
}
