#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for (char c : magazine)
            count[c - 'a']++;
        for (char c : ransomNote)
        {
            count[c - 'a']--;
            if (count[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string a = "a";
    string b = "b";
    s.canConstruct(a, b);
}