#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
    vector<int> twosum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hashmap; 
        int pos = 0;
        for(vector<int>::iterator it=nums.begin(); it != nums.end(); it++)
        {
            unordered_map<int, int>::iterator p;
            p = hashmap.find(target-(*it));
            cout << *it << endl;
            if (p != hashmap.end())
                return {p->second, pos};
            hashmap[*it] = pos;
            pos++;
        }
        return {};
    }
};

void print(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
}

int main()
{
    vector<int> v = {2, 7, 11, 15};
    solution s;
    vector<int> res = s.twosum(v, 9);
    //cout << res << endl;
    print(res);
}
