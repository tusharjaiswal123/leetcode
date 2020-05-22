PROBLEM:


A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time.The robot is trying to reach the bottom-right corner
of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:
Input: m = 7, n = 3
Output: 28
 

Constraints:

1. 1 <= m, n <= 100
2. It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.




SOLUTION:


class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=1;
                }
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[n-1][m-1];
        
    }
};
