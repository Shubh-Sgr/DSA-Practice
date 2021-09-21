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
    TreeNode* build(vector<int> inorder,vector<int> postorder,int left,int right,int &parIdx)
    {
        if (left>right)
        {
            return NULL;
        }
        
        int inIdx;
        TreeNode* root=new TreeNode(postorder[parIdx--]);
        for (int i=left; i<=right; i++)
        {
            if (inorder[i] == root->val)
            {
                inIdx=i;
                break;
            }
        }
        root->right=build(inorder, postorder,inIdx+1,right,parIdx);
        root->left=build(inorder, postorder,left,inIdx-1,parIdx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int parIdx=inorder.size()-1;
        return build(inorder, postorder,0,inorder.size()-1,parIdx);
    }
};
