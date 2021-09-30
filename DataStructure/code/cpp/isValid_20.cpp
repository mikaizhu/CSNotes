class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (char c : s)
        {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            // 进过上面if else后，如果stack为空，说明没有左括号，输入只有右括号
            else if (st.empty() || st.top() != c) return false;
            else st.pop();
        }
        return st.empty();
    }
};
