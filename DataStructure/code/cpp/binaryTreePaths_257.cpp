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
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
        // 要先添加进去
        path.push_back(cur->val);
        // 如果遇到叶子节点，则把这个路径的所有节点，转换成字符串，并添加到res中
        if (cur->left == NULL && cur->right == NULL) {
            string s;
            int _size = path.size() - 1;
            for (int i = 0; i < _size; i++) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[_size]);
            res.push_back(s);
            return;
        };
        // 将根节点记录到路径中

        if (cur->left) {
            traversal(cur->left, path, res);
            path.pop_back(); // 一定要记得回溯
        }
        if (cur->right) {
            traversal(cur->right, path, res);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res;
        traversal(root, path, res);
        return res;
    }
};
