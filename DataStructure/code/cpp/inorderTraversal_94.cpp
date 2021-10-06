class Solution {
public:
    void traversal(TreeNode *root, vector<int>& res) {
        if (root == NULL) return;
        this->traversal(root->left, res);
        res.push_back(root->val);
        this->traversal(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        this->traversal(root, res);
        return res;
    }
};
