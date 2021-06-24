PROBLEM:


There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent four cells in
the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary.
Since the answer can be very large, return it modulo 109 + 7.

 
Example 1:
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

  
Example 2:
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

Constraints:
1. 1 <= m, n <= 50
2. 0 <= maxMove <= 50
3. 0 <= startRow <= m
4. 0 <= startColumn <= n



SOLUTION:


class Solution {
    int mod = 1000000007;
    long long dp[51][51][51];
    
public:
    
    long long dfs(int n,int m,int x,int y,int move)
    {
        if(move<0)
            return 0;
        
        if(x<0 || y<0 || x>=n || y>=m)
            return 1;
        
        if(dp[x][y][move]!=-1)
            return dp[x][y][move];
        
        long long ans=0;
        
        ans = (ans%mod + dfs(n,m,x+1,y,move-1)%mod)%mod;
        ans = (ans%mod + dfs(n,m,x,y+1,move-1)%mod)%mod;
        ans = (ans%mod + dfs(n,m,x-1,y,move-1)%mod)%mod;
        ans = (ans%mod + dfs(n,m,x,y-1,move-1)%mod)%mod;
        
        return dp[x][y][move] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof dp);
        return dfs(m,n,startRow,startColumn,maxMove);
    }
};
