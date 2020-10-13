PROBLEM:



Given the head of a linked list, return the list after sorting it in ascending order.
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?


Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
 
Constraints:
1.The number of nodes in the list is in the range [0, 5 * 104].
2. -105 <= Node.val <= 105





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
    
    ListNode* merge(ListNode *l,ListNode *r)
    {   
        ListNode dump(0);
        ListNode *cur=&dump;
        
        
        while(l!=NULL && r!=NULL)
        {
            if(l->val<r->val)
            {
                cur->next=l;
                l=l->next;
            }
            else
            {
                cur->next=r;
                r=r->next;
            }
            cur=cur->next;
        }
        
        if(l!=NULL)
        {
            cur->next=l;
        }
        
        if(r!=NULL)
        {
            cur->next=r;
        }
        
        return dump.next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *slow,*fast,*r;
        slow=head;
        fast=head->next;
        
        
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        
        r=slow->next;
        slow->next=NULL;
        
        return merge(sortList(head),sortList(r));
    }
    
    
};
