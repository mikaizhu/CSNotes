class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s += string(s.begin(), s.begin() + n + 1);
        return string(s.begin() + n + 1, s.end());
    }
};
