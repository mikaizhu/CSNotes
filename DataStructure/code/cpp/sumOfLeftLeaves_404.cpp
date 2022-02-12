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
    int sumOfLeftLeaves(TreeNode* root) {
        // 递归三部曲
        // 1. 判断递归函数的返回值和参数: 返回值为该子树的左叶子之和，参数为该节点
        // 2. 确定退出递归的条件: 当前节点是否为空
        // 3. 确定每层的逻辑：返回当前子树的左节点之和
        if (root == NULL) return 0;
        
        int res = 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            res += root->left->val;
        }

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + res;
    }
};
