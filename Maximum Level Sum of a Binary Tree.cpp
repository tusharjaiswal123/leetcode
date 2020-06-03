PROBLEM:



Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 
Example 1:
Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
 

Note:

1. The number of nodes in the given tree is between 1 and 10^4.
2. -10^5 <= node.val <= 10^5




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
    int maxLevelSum(TreeNode* root) {
        
        if(root==NULL)
            return 1;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        
        int l=1,sum=0,mx=INT_MIN,res;
        
    
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            
            if(temp.second==l)
            {
                sum+=(temp.first)->val;
            }
            else
            {
                if(sum>mx)
                {
                    mx=sum;
                    res=l;
                }
                sum=(temp.first)->val;
                l++;
            }
            
            
            if((temp.first)->left!=NULL)
                q.push({(temp.first)->left,temp.second+1});
            
            if((temp.first)->right!=NULL)
                q.push({(temp.first)->right,temp.second+1});
            
        }
        
        if(sum>mx)
        {
            res=l;
        }
        
        return res;
        
    }
};
