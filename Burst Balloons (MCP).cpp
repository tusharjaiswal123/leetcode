PROBLEM:



Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons.
If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst,
the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
1. You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
2. 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
             
             
             
SOLUTION:



class Solution {
public:
    
    int calc(vector<int>& a,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int k,ans=INT_MIN;
        
        for(k=i;k<=j;k++)
        {
            ans = max(ans,a[i-1]*a[k]*a[j+1] + calc(a,i,k-1,dp) + calc(a,k+1,j,dp));
        }
            
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int i,j,n,ans;
        n=nums.size();
        vector<int> a(n+2);
        a[0]=1;
        
        i=1;
        for(auto k:nums)
        {
            a[i++]=k;
        }
        a[i]=1;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        ans = calc(a,1,n,dp);
        
        return ans;
        
    }
};
