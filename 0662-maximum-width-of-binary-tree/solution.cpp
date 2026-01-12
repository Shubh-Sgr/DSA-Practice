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
    using ll = long long;
    int widthOfBinaryTree(TreeNode* root) {
        if (!root){
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        int maxWid=0;
        q.push({root,0});
        while (!q.empty()){
            int n = q.size();
            ll st=q.front().second;
            ll end = q.back().second;
            for (int i=0; i<n; i++){
                pair<TreeNode*,int> p = q.front();
                q.pop();
                TreeNode* temp = p.first;
                int ind = p.second;
                if (temp->left){
                    q.push({temp->left,(ll) 2 * ind});
                }
                if (temp->right){
                    q.push({temp->right,(ll) 2 * ind +1});
                }  
            }
             maxWid = max(maxWid, int(end-st+1));  
        }
        return maxWid;
    }
};
