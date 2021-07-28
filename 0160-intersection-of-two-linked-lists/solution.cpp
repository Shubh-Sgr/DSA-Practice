/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         int n1=0;
    int n2=0;
    ListNode* temp1=headA;
    ListNode* temp2=headB;
    while (temp1!=NULL)
    {
        n1++;
        temp1=temp1->next;
    }
    while (temp2!=NULL)
    {
        n2++;
        temp2=temp2->next;
    }
    int diff=abs(n1-n2);
        cout<<diff<<" ";
    while (diff!=0)
    {
        if (n1>n2)
        {
            headA=headA->next;
        }
        else
        {
            headB=headB->next;
        }
        diff--;
    }
    // cout<<head1->data<<" "<<head2->data<<" ";
        cout<<headA->val<<" "<<headB->val;
    while (headA!=NULL)
    {
        if (headA==headB)
        {
            return headA;
        }
        else
        {
            headA=headA->next;
            headB=headB->next;
        }
    }
    return NULL;
    }
};
