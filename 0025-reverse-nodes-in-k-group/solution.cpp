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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head){
            return NULL;
        }
        int size = 0;
        ListNode* temp = head;
        while (temp){
            temp=temp->next;
            size++;
        }
        return reverseUtil(head,k,size);
    };

    ListNode* reverseUtil(ListNode* head, int k,int size){
        if (!head){
            return NULL;
        }
        if (k>size){
            return head;
        }
        int n = k;
        ListNode* temp = head;
        ListNode* lastNode = head;
        ListNode* prev = NULL;
        while (n !=0 && temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev= temp;
            temp = next;
            n--;
        };
        size=size-k;
        lastNode->next = reverseUtil(temp,k,size);
        return prev;
    }
};
