// 方法1
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

// 方法2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (cur != NULL || !st.empty()) {
            // 遍历到最左边的节点
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            // 遍历到最左边后，可以开始返回
            // 此时cur为空
            else {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

// 方法3
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == NULL) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            if (cur != NULL) {
                st.pop();
                if (cur->right) st.push(cur->right);
                st.push(cur); // 为中间节点加入标记
                st.push(NULL); // 因为每个节点都可能是中间节点，所以不需要为左右加标记NULL
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

