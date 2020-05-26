PROBLEM:



Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3



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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        ListNode *temp,*prev,*t;
        
        temp=head->next;
        prev=head;
        
        while(temp!=NULL)
        {
            if(prev->val==temp->val)
            {   
                t=temp;
                prev->next=t->next;
                temp=prev->next;
                delete(t);
            }
            else
            {
                temp=temp->next;
                prev=prev->next;
            }
            
        }
        
        return head;
    }
};
