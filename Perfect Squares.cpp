PROBLEM:




Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.



SOLUTION:



class Solution {
    private:
    const int inf=1e9;
public:
    
    int numSquares(int n) {
        
        int i,j;
        vector<int> dp(n+1,inf);
        dp[0]=0;
        
        for(i=1;i*i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i*i<=j)
                {
                    dp[j]=min(dp[j],dp[j-i*i]+1);
                }
            }
        }
        
        return dp[n];
        
    }
};
