PROBLEM:


Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5



SOLUTION:



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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
            return NULL;
        
        ListNode *t,*prev,*temp;
        t=head;
        prev=NULL;
        
        while(t!=NULL)
        {
            if(t->val==val)
            {   
                if(prev==NULL)
                {
                    temp=head;
                    head=head->next;
                    delete(temp);
                    t=head;
                }
                else
                {
                    temp=t;
                    prev->next=t->next;
                    delete(temp);
                    t=prev->next;
                }
            }
            else
            {
                prev=t;
                t=t->next;
            }
        }
        
        return head;
    }
};
