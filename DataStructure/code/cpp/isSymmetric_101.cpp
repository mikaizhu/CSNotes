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
// 思路：因为树有左右两个子树，所以遍历的方式为分别遍历左右两颗子树
// 左子树从左往右遍历，右子树从右往左遍历，但遍历是同步的
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = que.front();
                que.pop();
                if (cur == NULL) vec.push_back(-1);
                else {
                    vec.push_back(cur->val);
                    if (cur->left) que.push(cur->left);
                    else que.push(NULL);
                    if (cur->right) que.push(cur->right);
                    else que.push(NULL);
                }
            }
            int left = 0, right = vec.size() - 1;
            while (left < right) {
                if (vec[left] != vec[right]) return false;
                left++;
                right--;
            }
        }
        return true;
    }
};


// 相当于利用双指针分别对左右子树遍历
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == NULL) return true;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            // 开始分别遍历左右子树
            TreeNode *_left = que.front(); que.pop();
            TreeNode *_right = que.front(); que.pop();
            
            if (!_left && !_right) continue;

            // 寻找为false的条件，为true则往下继续执行
            // 左右两边有一个为空节点
            // 左右两边值不一样
            if ((!_left || !_right) || (_left->val != _right->val)) return false;

            // 开始添加节点，进行下一层遍历
            que.push(_left->left);
            que.push(_right->right);
            que.push(_left->right);
            que.push(_right->left);
        }
        return true;
    }
};

