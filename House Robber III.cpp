PROBLEM:



The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root,
each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree".
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.


Example 2:
Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.





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
    
    int calc(TreeNode* root,map<pair<TreeNode*,int>,int> &m,int f)
    {   
        if(root==NULL)
            return 0;
        
        if(m.find({root,f})!=m.end())
            return m[{root,f}];
        
        int ans;
        
        if(f==1)
        {  
            ans =  calc(root->left,m,0)+calc(root->right,m,0);
        }
        else
        {
            ans = max({calc(root->left,m,0)+calc(root->right,m,0), root->val + calc(root->left,m,1)
                       + calc(root->right,m,1)});
        }
        
        
        return m[{root,f}]=ans;
    }
    
    int rob(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        map<pair<TreeNode*,int>,int> m;
        int ans = calc(root,m,0);
        
        return ans;
    }
};
