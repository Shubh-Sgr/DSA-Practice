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
    TreeNode* buildTree(vector<int> preorder,vector<int> inorder,int inSt,int inEnd,int &pre,unordered_map<int,int> ump)
    {
        if (inSt>inEnd)
        {
            return NULL;
        }
        int parInd=ump[preorder[pre]];
        pre++;
        TreeNode* node=new TreeNode(inorder[parInd]);
        node->left=buildTree(preorder,inorder,inSt,parInd-1,pre,ump);
        node->right=buildTree(preorder,inorder,parInd+1,inEnd,pre,ump);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> ump;
        int n=inorder.size();
        for (int i=0; i<n; i++)
        {
            ump[inorder[i]]=i;
        }
        int pre=0;
        return buildTree(preorder,inorder,0,n-1,pre,ump);
    }
};
