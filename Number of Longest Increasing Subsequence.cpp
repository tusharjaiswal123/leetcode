PROBLEM:


Given an integer array nums, return the number of longest increasing subsequences.


Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 
Constraints:
1. 0 <= nums.length <= 2000
2. -106 <= nums[i] <= 106





SOLUTION:




class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int i,j,n,ans=0,l=1,c;
        n=nums.size();
        
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {   
                    if(dp[i]==dp[j]+1)
                        cnt[i]+=cnt[j];
                    else if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            l=max(l,dp[i]);
        }
        
        
        for(i=0;i<n;i++)
        {
            if(dp[i]==l)
                ans+=cnt[i];
        }
        
       
        
        return ans;
        
    }
};
