PROBLEM:


You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

 
Follow up:
1. You may only use constant extra space.
2. Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 
Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:
1.The number of nodes in the given tree is less than 4096.
2.-1000 <= node.val <= 1000






SOLUTION:





/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
            return NULL;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            auto k=q.front();
            q.pop();
            
            if(k==NULL)
            {
                if(q.size()>0)
                    q.push(NULL);
            }
            else
            {   
                if(!q.empty())
                {
                    k->next=q.front();
                }
                
                if(k->left!=NULL)
                    q.push(k->left);
                
                if(k->right!=NULL)
                    q.push(k->right);
            }
            
        }
        
        return root;
        
    }
};


O(1) space:


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void helper(Node* root)
    {
        if(root==NULL)
            return;
        
        if(root->left!=NULL)
            root->left->next = root->right;
        
        if(root->next!=NULL)
            root->right->next = root->next->left;
        
        helper(root->left);
        helper(root->right);
        
    }
    
    
    Node* connect(Node* root) {
        
        if(root==NULL)
            return NULL;
        
        helper(root);
        
        return root;
        
    }
};
