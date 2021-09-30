class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s)
        {
            if (st.empty() || st.top() != c)
                st.push(c);
            else if (st.top() == c)
                st.pop();
        }
        s = string("");
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char c : s)
        {
            if (res.empty() || res.back() != c)
                res.push_back(c);
            else
                res.pop_back();
        }
        return res;
    }
};

