PROBLEM:




You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11







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
    
    void dfs(TreeNode* root,int sum,map<int,int> &m,int cumm_sum,int &ans)
    {
        if(root==NULL)
            return;
        
        cumm_sum+=root->val;
        
        if(m[cumm_sum-sum]>0)
        {   
            ans+=m[cs-sum];
        }
        
        
        m[cs]++;
        
        dfs(root->left,sum,m,cs,ans);
        dfs(root->right,sum,m,cs,ans);
        
        m[cs]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
            return 0;
        
        map<int,int> m;
        int ans=0;
        m[0]=1;
        
        dfs(root,sum,m,0,ans);
        
        return ans;
        
    }
};
