PROBLEM:



Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.
A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.

 
Example 1:
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.


Example 2:
Input: root = [1,null,2,null,0,3]
Output: 3
 

Constraints:
1. The number of nodes in the tree is in the range [2, 5000].
2. 0 <= Node.val <= 105






SOLUTION:


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void helper(TreeNode* root,int mn,int mx,int &ans)
    {
        if(root==NULL)
            return;
        
        ans = max({ans,abs(root->val-mn),abs(root->val-mx)});
        
        helper(root->left,min(root->val,mn),max(root->val,mx),ans);
        helper(root->right,min(root->val,mn),max(root->val,mx),ans);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int mn,mx,ans=INT_MIN;
        mn=mx=root->val;
        
        helper(root,mn,mx,ans);
        
        return ans;
        
    }
};
