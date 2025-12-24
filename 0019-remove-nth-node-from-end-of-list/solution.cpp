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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 1;

        while (curr){
            curr = curr->next;
            len++;
        };

        int numTBD = (len-n)-1;
        if (numTBD == 0){
            return head->next;
        }

        curr = head;
        ListNode* prev = NULL;
        for (int i=0; i<numTBD; i++){
            prev = curr;
            curr = curr->next;
        }

        if (!curr){
            prev->next = NULL;
        }
        else{
            ListNode* next = curr->next;
            curr->next = NULL;
            prev->next = next;
        }
        return head;
    }
};
