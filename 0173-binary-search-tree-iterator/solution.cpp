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
class BSTIterator {
public:
    stack<int> s;
    void rightTraverse(TreeNode* root,stack<int> &s){
        if (!root){
            return;
        }
        rightTraverse(root->right,s);
        s.push(root->val);
        rightTraverse(root->left,s);
    }
    
    BSTIterator(TreeNode* root) {
        rightTraverse(root,s);
    }
    
    int next() {
        if (!s.empty()){
            int ans = s.top();
            s.pop();
            return ans;
        }
        return -1;
    }
    
    bool hasNext() {
        return (!s.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
