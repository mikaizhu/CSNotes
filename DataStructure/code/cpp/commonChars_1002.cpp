#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int common[26] = {0};
        for (int i = 0; i < words.size(); i++)
        {
            int temp[26] = {0};
            for (int j = 0; j < words[i].size(); j++)
            {
                char word = words[i][j];
                if (i == 0)
                    common[word - 'a']++;
                else
                    temp[word - 'a']++;
            }
            if (i == 0)
                continue;
            else
            {
                for (int i = 0; i < 26; i++)
                    common[i] = min(common[i], temp[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; i++)
        {
            if (common[i] != 0)
            {
                string s(1, i + 'a');
                for (int j = 0; j < common[i]; j++)
                    res.push_back(s);
            }
        }
        return res;
    }
};

int main()
{
    vector<string> t = {"bella", "label", "roller"};
    Solution s;
    t = s.commonChars(t);
}
