/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
bool dfs(TreeNode* node, int target) {
    if(node == NULL)
        return false;

    target -= node->val;

    if(node->left == NULL && node->right == NULL)
        return target == 0;

    return dfs(node->left, target) ||
           dfs(node->right, target);
}
    bool hasPathSum(TreeNode* root, int targetSum) { 
        return dfs(root,targetSum);
    }
};