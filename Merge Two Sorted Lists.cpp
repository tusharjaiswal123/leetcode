PROBLEM:



Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the
first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4




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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *head=NULL,*t;
        
        while(l1!=NULL && l2!=NULL)
        {   
            ListNode* newnode;
            if(l1->val<l2->val)
            {
                newnode = new ListNode(l1->val);
                l1=l1->next;
            }
            else
            {
                newnode = new ListNode(l2->val);
                l2=l2->next;
            }
            
            if(head==NULL)
            {   
                head=newnode;
                t=head;
            }
            else
            {
                t->next=newnode;
                t=t->next;
            }
        }
        
        while(l1!=NULL)
        {
            ListNode* newnode = new ListNode(l1->val);
            l1=l1->next;
            
            if(head==NULL)
            {
                head=newnode;
                t=head;
            }
            else
            {
                t->next=newnode;
                t=t->next;
            }
        }
        
        
         while(l2!=NULL)
        {
            ListNode* newnode = new ListNode(l2->val);
            l2=l2->next;
            
            if(head==NULL)
            {
                head=newnode;
                t=head;
            }
            else
            {
                t->next=newnode;
                t=t->next;
            }
        }
        
        return head;
        
    }
};
