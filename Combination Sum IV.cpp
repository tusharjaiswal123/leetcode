PROBLEM:



Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:
nums = [1, 2, 3]
target = 4
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.
Therefore the output is 7.
 

Follow up:
1. What if negative numbers are allowed in the given array?
2. How does it change the problem?
3. What limitation we need to add to the question to allow negative numbers?





SOLUTION:




class Solution {
    private:   
    int n;
    int calc(vector<int> &nums,int sum,vector<int> &dp)
    {
        if(sum==0)       //we get required sum
            return 1;
        
        if(sum<0)
            return 0;
        
        if(dp[sum]!=-1)
            return dp[sum];
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=calc(nums,sum-nums[i],dp);
        }
        
        return dp[sum]=ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        n=nums.size();
        vector<int> dp(target+1,-1);   // state dp[s] represent number of permuatations to reach 
                                       // sum s using any element any number of times
    
        return calc(nums,target,dp);;
    }
};
