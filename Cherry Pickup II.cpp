PROBLEM:



Given a rows x cols matrix grid representing a field of cherries. Each cell in grid represents the number of cherries that you can collect.
You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located at the top-right corner (0, cols-1) of the
grid.

Return the maximum number of cherries collection using both robots  by following the rules below:

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
When both robots stay on the same cell, only one of them takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in the grid.
 

Example 1:
Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.


Example 2:
Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.


Example 3:
Input: grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
Output: 22


Example 4:
Input: grid = [[1,1],[1,1]]
Output: 4
 

Constraints:

1. rows == grid.length
2. cols == grid[i].length
3. 2 <= rows, cols <= 70
4. 0 <= grid[i][j] <= 100 




SOLUTION:


class Solution {
public:
    int dp[72][72][72];
    
    int calc(vector<vector<int>> &grid,int n,int m,int row,int c1,int c2)
    {
        if(c1<0 || c2<0 || c1>=m || c2>=m || row>=n)
        return 0;
        
        if(dp[row][c1][c2]!=-1)
            return dp[row][c1][c2];
        
        int c=0,ans=0;
        ans = grid[row][c1];
        
        if(c1!=c2)
            ans+=grid[row][c2];
        
   
        for(int i=c1-1;i<=c1+1;i++)
        {
            for(int j=c2-1;j<=c2+1;j++)
            {
                c = max(c,calc(grid,n,m,row+1,i,j));
            }
        }
        
        ans+=c;
        return dp[row][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int i,j,n,m,ans;
        n=grid.size();
        m=grid[0].size();
        
        memset(dp,-1,sizeof dp);
       
        return calc(grid,n,m,0,0,m-1);
    }
};
