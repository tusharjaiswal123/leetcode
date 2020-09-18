PROBLEM:


Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm
to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.



SOLUTION:


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i,n,ans=0,mn=INT_MAX;
        n=prices.size();
        
        for(i=0;i<n;i++)
        {
            mn=min(mn,prices[i]);
            ans=max(ans,prices[i]-mn);
        }
        
        
        return ans;
    }
};




DP solution:



class Solution {
    private:
    int calc(vector<int> &prices,int n,int i,int f,vector<vector<int>> &dp)
    {   
        if(i==n)
            return 0;
        
        if(dp[i][f]!=-1)
            return dp[i][f];
        
        int ans=calc(prices,n,i+1,f,dp);
        if(f==0)
        {
            ans = max(ans,-prices[i] + calc(prices,n,i+1,1,dp));  
        }
        else if(f==1)
        {
            ans = max(ans,prices[i]);
        }
        
        return dp[i][f]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int i,n,ans;
        n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        ans=calc(prices,n,0,0,dp);
        
        return ans;
        
    }
};
