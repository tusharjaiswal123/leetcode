PROBLEM:




Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
1. All numbers (including target) will be positive integers.
2. The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]





SOLUTION:




class Solution {
    private:
    vector<vector<int>> ans;
    int n;
    vector<int> v;
    void calc(vector<int> &candidates,int i,int sum,int target)
    {
        if(sum == target)    //If we get target sum then store the answer
        {   
            ans.push_back(v);
            return;
        }
        
        if(i==n)          //We have crossed the index of last element
            return;
        
        if(sum > target)             //if our sum exceeds the target sum
            return;
    
        
        v.push_back(candidates[i]);      //Include the current element
        calc(candidates,i+1,sum+candidates[i],target);  //Recursion
        v.pop_back();         //Backtrack
        
        int val=candidates[i];
        while(i<n && val == candidates[i])
            i++;
        
        calc(candidates,i,sum,target); 
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());
        calc(candidates,0,0,target);
        
        
        return ans;
    }
};
