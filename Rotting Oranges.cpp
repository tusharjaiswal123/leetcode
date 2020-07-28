PROBLEM:


In a given grid, each cell can have one of three values:
the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 
Example 1:
Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 
Note:

1. 1 <= grid.length <= 10
2. 1 <= grid[0].length <= 10
3. grid[i][j] is only 0, 1, or 2.





SOLUTION:



class Solution {
public:
    
    bool canRot(vector<vector<int>> &grid,vector<vector<bool>> &vis,int n,int m,int x,int y)
    {
        if(x<0 || y<0 || x>=n || y>=m || vis[x][y]==true || grid[x][y]==0)
            return false;
        
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int i,j,n,m,ans=0,s;
        n=grid.size();
        m=grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {   
                    q.push({i,j});
                    ans=-1;
                    vis[i][j]=true;
                }
            }
        }
        
        while(!q.empty())
        {   
            s=q.size();
            ans++;
            while(s--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                if(canRot(grid,vis,n,m,x+1,y))
                {
                    q.push({x+1,y});
                    vis[x+1][y]=true;
                    grid[x+1][y]=2;
                }
                    
                if(canRot(grid,vis,n,m,x-1,y))
                {
                    q.push({x-1,y});
                    vis[x-1][y]=true;
                    grid[x-1][y]=2;
                }
                
                if(canRot(grid,vis,n,m,x,y+1))
                {
                    q.push({x,y+1});
                    vis[x][y+1]=true;
                    grid[x][y+1]=2;
                }
                
                if(canRot(grid,vis,n,m,x,y-1))
                {
                    q.push({x,y-1});
                    vis[x][y-1]=true;
                    grid[x][y-1]=2;
                }
            }
            
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return ans;
        
    }
};
