PROBLEM:


You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if
two adjacent houses were broken into on the same night.
Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 
Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [0]
Output: 0
 
Constraints:
1. 1 <= nums.length <= 100
2. 0 <= nums[i] <= 1000




SOLUTION:


class Solution {
public:
    int calc(vector<int> &nums,int n,int i,vector<int> &dp)
    {   
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans = calc(nums,n,i+1,dp);
        ans=max(ans,nums[i]+calc(nums,n,i+2,dp));
        
        return dp[i]=ans;
    }
    
    int rob(vector<int>& nums) {
        
        int n,i,ans;
        n=nums.size();
        
        vector<int> dp(n,-1);
        ans=nums[0] + calc(nums,n-1,2,dp);
        
        for(i=0;i<n;i++)
        dp[i]=-1;
        
        ans=max(ans,calc(nums,n,1,dp));
        
        return ans;
    }
};
