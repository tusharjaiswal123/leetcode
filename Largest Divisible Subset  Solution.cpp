PROBLEM:



Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.


Example 1:
Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]


SOLUTION:


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int i,j,n,ans=INT_MIN,f=0,p;
        n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<int> dp(n,1);
        vector<int> v;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                    dp[i]=max(dp[i],1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        
        for(i=n-1;i>=0;i--)
        {
            if(dp[i]==ans && f==0)
            {
                v.push_back(nums[i]);
                p=nums[i];
                ans--;
                f=1;
            }
            else if(dp[i]==ans && f==1 && p%nums[i]==0)
            {
                v.push_back(nums[i]);
                p=nums[i];
                ans--;
            }
        }
        
        
        reverse(v.begin(),v.end());
        
        return v;
            
        
    }
};
