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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            long long prev;
            if (level % 2 == 0)
                prev = LLONG_MIN; 
            else
                prev = LLONG_MAX; 
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                int val = node->val;
                if (level % 2 == 0) {
                    if (val % 2 == 0 || val <= prev)
                        return false;
                } else {
                    if (val % 2 == 1 || val >= prev)
                        return false;
                }
                prev = val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};