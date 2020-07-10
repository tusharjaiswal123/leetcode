PROBLEM:


You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly
linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.
Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 
Example 1:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]

Example 2:
Input: head = [1,2,null,3]
Output: [1,3,2]

Example 3:
Input: head = []
Output: []
 
 
Constraints:
1. Number of Nodes will not exceed 1000.
2. 1 <= Node.val <= 10^5




SOLUTION:



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head==NULL)
            return head;
        
        Node *p,*nxt,*q;
        p=head;
        
        while(p)
        {
            if(p->child!=NULL)
            {
                nxt=p->next;
                p->next=p->child;
                p->child->prev=p;
                
                p->child=NULL;
                
                q=p->next;
                
                while(q->next!=NULL)
                    q=q->next;
                
                if(nxt!=NULL)
                {
                    q->next=nxt;
                    nxt->prev=q;
                }
            }
            
            p=p->next;
        }
        
        return head;
        
    }
};
