PROBLEM:



In an N by N square grid, each cell is either empty (0) or blocked (1).
A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:
Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 
Example 1:
Input: [[0,1],[1,0]]
Output: 2

Example 2:
Input: [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

 
Note:
1. 1 <= grid.length == grid[0].length <= 100
2. grid[r][c] is 0 or 1




SOLUTION:




class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int i,j,n,r,c,mx,d=0,sz;
        n = grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty())
        {   
            sz=q.size();
            d++;
            
            while(sz--)
            {
                auto k=q.front();
                q.pop();
            
                if(k.first==n-1 && k.second==n-1)
                    return d;
            
                for(i=-1;i<=1;i++)
                {
                    for(j=-1;j<=1;j++)
                    {   
                        r=k.first+i;
                        c=k.second+j;
                    
                        if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==0)
                        {
                            q.push({r,c});
                            grid[r][c] = 1; //marking as visited
                        
                        }
                    }
                }
            }
        }
    
        return -1;
    }
};
