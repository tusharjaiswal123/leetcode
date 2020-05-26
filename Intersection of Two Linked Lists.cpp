PROBLEM:


Write a program to find the node at which the intersection of two singly linked lists begins.



SOLUTION:



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
        
        ListNode *t1=headA,*t2=headB;
        
        while(t1!=t2)
        {
            if(t1!=NULL)
                t1=t1->next;
            else if(t1==NULL)
                t1=headB;
            
            if(t2!=NULL)
                t2=t2->next;
            else if(t2==NULL)
                t2=headA;
        }
        
        return t1;
    }
};
