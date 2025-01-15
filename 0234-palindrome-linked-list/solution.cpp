/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return checkIfPall(head);
    }
    
    bool checkIfPall(ListNode* curr) {
        if (!curr){
            return true;
        }
        bool isPall = checkIfPall(curr->next) && (temp->val == curr->val);
        temp = temp->next;
        return isPall;
    }
};
