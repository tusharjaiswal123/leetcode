PROBLEM:


You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col).
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right,
and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 
Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.


Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].


Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:
1. rows == heights.length
2. columns == heights[i].length
3. 1 <= rows, columns <= 100
4. 1 <= heights[i][j] <= 106




SOLUTION:

Binary Search + BFS


class Solution {
public:
    
    bool bfs(vector<vector<int>> &heights,int n,int m,int mid)
    {   
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int i,x,y;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        
        while(!q.empty())
        {
            auto k=q.front();
            q.pop();
            
            if(k.first==n-1 && k.second==m-1)
                return true;
            
            for(i=0;i<4;i++)
            {
                x=k.first+dx[i];
                y=k.second+dy[i];
                
                if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==false && 
                   abs(heights[k.first][k.second]-heights[x][y])<=mid)
                {   
                    vis[x][y]=true;
                    q.push({x,y});
                }
            }
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n,m,i,j,ans,mid,l,h;
        n = heights.size();
        m = heights[0].size();
        
        l=0;
        h=1000000;
        
        while(l<=h)
        {
            mid = l+(h-l)/2;
            
            if(bfs(heights,n,m,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        
        return ans;
        
        
    }
};
