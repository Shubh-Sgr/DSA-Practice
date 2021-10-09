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
    int maxSumUtil(TreeNode* root,int &Max)
    {
        if (!root)
        {
            return 0;
        }
        int left=maxSumUtil(root->left,Max);
        int right=maxSumUtil(root->right,Max);
        int tempMax=max(max(left,right)+root->val,root->val);
        Max=max(Max,max(tempMax,left+right+root->val));
        return tempMax;
    }
    
    int maxPathSum(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int Max=root->val;
        maxSumUtil(root,Max);
        return Max;
    }
};
