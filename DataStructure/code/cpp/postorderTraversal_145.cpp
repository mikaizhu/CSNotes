/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode *root, vector<int>& res) {
        if (root == NULL) return;
        this->traversal(root->left, res);
        this->traversal(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == NULL) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            res.push_back(cur->val); // 中
            if (cur->left) st.push(cur->left); // 左
            if (cur->right) st.push(cur->right); // 右
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == NULL) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            if (cur != NULL) {
                st.pop();
                st.push(cur); // 为中间节点加入标记
                st.push(NULL); // 因为每个节点都可能是中间节点，所以不需要为左右加标记NULL
                if (cur->right) st.push(cur->right);
                if (cur->left) st.push(cur->left);
            }
            else {
                // 如果遇到该节点是标记的, 那么就将这个节点放入结果中
                st.pop(); // 处理下一个不为空的节点
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
            }
        }
        return res;
    }
};


