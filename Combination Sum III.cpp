PROBLEM:



Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:
1. All numbers will be positive integers.
2. The solution set must not contain duplicate combinations.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]




SOLUTION:




class Solution {
    private:
    vector<vector<int>> ans;
    vector<int> v;
    
    void calc(int n,int k,int p,int s)
    {   
        if(s==n && k==0)
        {  
            ans.push_back(v);
            return;
        }
        
        if(k<0)
            return;
        
        if(s>n)
            return;
        
        for(int i=p+1;i<=9;i++)
        {
            v.push_back(i);
            calc(n,k-1,i,s+i);
            v.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        calc(n,k,0,0);
        
        return ans;
    }
};
