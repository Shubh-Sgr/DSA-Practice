/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int util(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if (!root){
            return INT_MIN;
        }
        int finalVal = INT_MIN;
        if (root->val == p->val || root->val == q->val){
            finalVal = root->val;
        }
        int left = util(root->left,p,q,ans);
        int right = util(root->right,p,q,ans);
        if (((left!=INT_MIN && right!=INT_MIN) || (left!=INT_MIN && finalVal!=INT_MIN) || (right!=INT_MIN && finalVal!=INT_MIN)) && !ans){
            ans = root;
        }
        if (left!=INT_MIN){
            finalVal = left;
        }else if(right!=INT_MIN) {
            finalVal = right;
        }
        return finalVal;
    } 
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        util(root,p,q,ans);
        return ans;
    }
};
