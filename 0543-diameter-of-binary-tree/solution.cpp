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
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
    }
    int rec(TreeNode* root, int &d) {
        if (!root){
            return 0;
        }
        int left = rec(root->left,d);
        int right = rec(root->right,d);
        if ((left+right)>d){
            d = left+right;
        }
        if (left>right){
            return left+1;
        }
        return right+1;
    }
};
