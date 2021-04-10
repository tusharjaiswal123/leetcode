PROBLEM:


Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 
Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1
 
Constraints:
1. m == matrix.length
2. n == matrix[i].length
3. 1 <= m, n <= 200
4. 0 <= matrix[i][j] <= 231 - 1




SOLUTION:



class Solution {
public:
 
    int dfs(vector<vector<int>> &matrix,int n,int m,int x,int y,int p,vector<vector<int>> &dp)
    {
        if(x<0 || y<0 || x>=n || y>=m || matrix[x][y]<=p)
            return 0;
        
        int ans;
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        
        ans = 1 + max({dfs(matrix,n,m,x+1,y,matrix[x][y],dp),dfs(matrix,n,m,x,y+1,matrix[x][y],dp),
                      dfs(matrix,n,m,x-1,y,matrix[x][y],dp),dfs(matrix,n,m,x,y-1,matrix[x][y],dp)});
        
        return dp[x][y] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n,m,i,j,ans=0;
        n = matrix.size();
        m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(dp[i][j]==-1)
                     dfs(matrix,n,m,i,j,-1,dp);
            }
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                ans=max(ans,dp[i][j]);
        }
        
        return ans;
    }
};
