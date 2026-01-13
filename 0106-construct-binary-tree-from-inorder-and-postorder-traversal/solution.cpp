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
    TreeNode *util(vector<int> inorder,vector<int> postorder,int &postInd, int st,int end){
        if (st>end){
            return NULL;
        }
        int inIdx = -1;
        for (int i=st; i<=end; i++){
            if (inorder[i] == postorder[postInd]){
                inIdx = i;
                break;
            }
        }
        postInd--;
        TreeNode* curr = new TreeNode(inorder[inIdx]);
        curr->right = util(inorder,postorder,postInd,inIdx+1,end);
        curr->left = util(inorder,postorder,postInd,st,inIdx-1);
        return curr;
    } 

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0){
            return NULL;
        }
        int n = inorder.size();
        int postInd = n-1;
        return util(inorder,postorder,postInd,0,n-1);
    }
};
