PROBLEM:



Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
Return the sum of these numbers.

 

Example 1:
Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:
1. The number of nodes in the tree is between 1 and 1000.
2. node.val is 0 or 1.
3. The answer will not exceed 2^31 - 1.








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
    private:
    
    void dfs(TreeNode* root,int n)
    {   
        if(root==NULL)
            return;
        
        if(root->val==0)
        {
            n=(n<<1);
        }
        else
        {
            n=(n<<1)|1;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            ans+=n;
            return;
        }
        
        dfs(root->left,n);
        dfs(root->right,n);
    }
    
public:
    int ans;
    
    int sumRootToLeaf(TreeNode* root) {
        
        ans=0;
        dfs(root,0);
        
        return ans;
    }
};
