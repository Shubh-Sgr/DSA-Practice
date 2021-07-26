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
        int num_front,total=0;
        ListNode* temp=head;
        ListNode* fnd_temp=head;
        ListNode* prev;
        while (temp!=NULL)
        {
            total++;
            temp=temp->next;
        }
        num_front=total-n+1;
        for (int i=1; i<num_front; i++)
        {
            prev=fnd_temp;
            fnd_temp=fnd_temp->next;
        }
        if (fnd_temp==head)
        {
            head=fnd_temp->next;
            fnd_temp->next=NULL;
        }
        else
        {
            prev->next=fnd_temp->next;
            fnd_temp->next=NULL;
        }
        return head;
    }
};
