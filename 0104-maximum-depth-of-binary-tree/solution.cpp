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
    void util(TreeNode* root, int &ans, int lvl){
        if (!root){
            return;
        }
        ans = max(lvl,ans);
        util(root->left, ans ,lvl+1);
        util(root->right, ans, lvl+1);
    }

    int maxDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxRight, maxLeft)+1;
    }
};
