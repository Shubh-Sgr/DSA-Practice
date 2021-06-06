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
    int max(int l,int r){
        return (l>r?l:r);
    }
    int maxSum(TreeNode* root,int &res){
        if (root==nullptr){
            return 0;
        }
        int l=maxSum(root->left,res);
        int r=maxSum(root->right,res);
        int temp=max(root->val+max(l,r),root->val);
        int ans=root->val+l+r;
        res=max(res,max(temp,ans));
        return temp;
        
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        maxSum(root,res);
        return res;
    }
};
