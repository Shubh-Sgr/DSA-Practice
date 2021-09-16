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
    int isBalancedUtil(TreeNode* root,bool &ans)
    {
        if (root==NULL)
        {
            return 0;
        }
        int left=isBalancedUtil(root->left,ans);
        int right=isBalancedUtil(root->right,ans);
        if (abs(left-right)>1)
        {
            ans=(ans && false);
        }
        if (left>right)
        {
            return left+1;
        }
        return right+1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        isBalancedUtil(root,ans);
        return ans;
    }
};
