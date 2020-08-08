PROBLEM:



Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]





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
    
    void dfs(TreeNode* root,int sum,vector<int> &v,vector<vector<int>> &ans)
    {   
        if(root==NULL)
            return;
        
        v.push_back(root->val);
        
        if(root->val==sum && root->left==NULL && root->right==NULL)
        {
            ans.push_back(v);
        }
        
        dfs(root->left,sum-root->val,v,ans);
        dfs(root->right,sum-root->val,v,ans);
        
        v.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> ans;
        vector<int> v;
        
        if(root==NULL)
            return ans;
        
        dfs(root,sum,v,ans);
        
        return ans;
        
    }
};
