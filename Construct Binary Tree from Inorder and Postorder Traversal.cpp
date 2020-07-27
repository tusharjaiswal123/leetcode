PROBLEM:



Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
   
   
   
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
    unordered_map<int,int> m;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        int idx=postorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1,idx);
        
    }
    
    TreeNode* build(vector<int> &inorder,vector<int> &postorder,int left,int right,int &rootIndex)
    {
        if(left>right)
            return NULL;
        
        int val=postorder[rootIndex];
        TreeNode* newnode=new TreeNode(val);
        int pivot=m[val];
        rootIndex--;
        
        newnode->right=build(inorder,postorder,pivot+1,right,rootIndex);
        newnode->left=build(inorder,postorder,left,pivot-1,rootIndex);
     
        
        return newnode;
    }
    
};
