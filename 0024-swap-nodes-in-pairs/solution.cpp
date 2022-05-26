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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = head;
        ListNode* temp = head;
        
        while (temp!=NULL && temp->next!=NULL)
        {
            ListNode *Next = temp->next;
            temp->next=temp->next->next;
            Next->next = temp;
            if (prev==head)
            {
                head=Next;
            }
            else
            {
                prev->next=Next;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
