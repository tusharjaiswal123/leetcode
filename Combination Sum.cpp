PROBLEM:




Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers
sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
1. All numbers (including target) will be positive integers.
2. The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

Constraints:

1. 1 <= candidates.length <= 30
2. 1 <= candidates[i] <= 200
3. Each element of candidate is unique.
4. 1 <= target <= 500





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
        
        calc(candidates,i+1,sum,target);     //Do not include current element and move forward
        
        v.push_back(candidates[i]);      //Include the current element
        calc(candidates,i,sum+candidates[i],target);  //Recursion
        v.pop_back();         //Backtrack
    }
	
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        calc(candidates,0,0,target);
        
        return ans;
    }
};
