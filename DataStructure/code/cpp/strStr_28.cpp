#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unistd.h>

using namespace std;

// 这种方法会超时
class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = 0, res = 0;
        if (needle == haystack) return res;
        for (int i = 0; i < haystack.size();)
        {
            res = i;
            while (i < haystack.size() && pos < needle.size() && needle[pos] == haystack[i])
            {
                pos++;
                i++;
            }
            if (pos == needle.size()) return res;
            else 
            {
                pos = 0;
                i = res + 1;
                while (i < haystack.size() && nums[i] == nums[i-1])
                    i++;
            }
        }
        return -1;
    }
};

int main()
{
}
