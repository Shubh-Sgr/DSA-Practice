/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* utils(Node* root){
        if (!root){
            return NULL;
        }
        if (root->left){
            root->left->next = root->right;
        }
        if (root->right){
            root->right->next = root->next ? root->next->left : NULL; 
        }
        utils(root->left);
        utils(root->right);
        return root;
    }
    Node* connect(Node* root) {
        if (!root){
            return NULL;
        }
        Node* leftBound = root;
        Node* curr = NULL;
        while (leftBound->left){
            curr = leftBound;
            while (curr){
                curr->left->next = curr->right;
                if (curr->next){
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            leftBound = leftBound->left;
        }
        return root;
    }
};
