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

// 二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数。

// 方法1 使用递归
// 递归三部曲
// 1. 确定递归函数的参数和返回值
//  传入参数为当前节点，以当前节点为根节点，返回当前节点的左右节点高度差
// 2. 确定递归的结束条件
//  如果遇到的节点为NULL，则推出递归
// 3. 确定递归每层的逻辑
//  判断以当前节点为根节点的子树，是否为平衡二叉树
class Solution {
public:
    int getHeight(TreeNode *node) {
        if (node == NULL) return 0; // 如果节点空，则返回以当前节点的子树高度为0
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;
        int res = max(leftHeight, rightHeight) - min(leftHeight, rightHeight);
        return res > 1 ? -1 : 1 + max(leftHeight, rightHeight); // 如果不平衡，则返回-1，否则返回该节点高度
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};

// 方法2: 使用迭代
class Solution {
public:
    int getHeight(TreeNode *node, int height) {
        queue<TreeNode*> que;
        if (cur != NULL) que.push(cur);
        int height = 0;
        while (!que.empty()) {

        }
        
        return height;
    }
    bool isBalanced(TreeNode* root) {

    }
};
