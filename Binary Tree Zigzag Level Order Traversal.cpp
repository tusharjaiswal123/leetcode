PROBLEM:



Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        vector<int> v;
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> s1,s2;
        s1.push(root);
        
        while(!s1.empty() || !s2.empty())
        {   
            while(!s1.empty())
            {
                auto k=s1.top();
                s1.pop();
                v.push_back(k->val);
                
                if(k->left!=NULL)
                    s2.push(k->left);
                
                if(k->right!=NULL)
                    s2.push(k->right);
            }  
            
            if(!v.empty())
            {
                ans.push_back(v);
                v.clear();
            }
            
            while(!s2.empty())
            {
                auto k=s2.top();
                s2.pop();
                v.push_back(k->val);
                
                if(k->right!=NULL)
                    s1.push(k->right);
                
                if(k->left!=NULL)
                    s1.push(k->left);
            }
            
            if(!v.empty())
            {
                ans.push_back(v);
                v.clear();
            }
            
            
        }
        
        return ans;
    }
};
