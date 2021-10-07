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
        res.push_back(root->val);
        this->traversal(root->left, res);
        this->traversal(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        this->traversal(root, res);
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == NULL) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top(); // 中
            st.pop();

            res.push_back(cur->val);
            // 因为出栈的顺序为左右
            if (cur->right) st.push(cur->right); // 右
            if (cur->left) st.push(cur->left); // 左
        }
        return res;
    }
};
