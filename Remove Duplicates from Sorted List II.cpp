PROBLEM:




Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3




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
        
        ListNode *c,*p,*n;
        c=head;
        n=c->next;
        p=NULL;
        
        
        while(n!=NULL)
        {   
            if(c->val==n->val)
            {
                while(n!=NULL && c->val==n->val)
                {
                    n=n->next;
                }   
                
                if(p==NULL)
                {
                    head=n;
                    c=n;
                    if(n!=NULL)
                    n=n->next;
                }
                else
                {
                    p->next=n;
                    c=n;
                    if(n!=NULL)
                        n=n->next;
                }
                
            }
            else
            {   
                p=c;
                c=n;
                n=n->next;
            }
            
            
        }
        
        return head;
        
    }
};
