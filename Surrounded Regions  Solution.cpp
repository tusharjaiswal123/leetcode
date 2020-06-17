PROBLEM:



Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected
if they are adjacent cells connected horizontally or vertically.





SOLUTION:



class Solution {
    private:
    void dfs(vector<vector<char>> &board,vector<vector<bool>> & vis,int n,int m,int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=m || board[x][y]=='X' || vis[x][y])
            return;
        
        vis[x][y]=true;
        
        dfs(board,vis,n,m,x+1,y);
        dfs(board,vis,n,m,x-1,y);
        dfs(board,vis,n,m,x,y+1);
        dfs(board,vis,n,m,x,y-1);
        
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int i,j,n,m;
        n=board.size();
        
        if(n!=0)
        {
        
            m=board[0].size();
            vector<vector<bool>> vis(n,vector<bool>(m,false));

            for(j=0;j<m;j++)
            {
                if(board[0][j]=='O' && !vis[0][j])
                {
                    dfs(board,vis,n,m,0,j);
                }

                if(board[n-1][j]=='O' && !vis[n-1][j])
                {
                    dfs(board,vis,n,m,n-1,j);
                }
            }

            for(i=1;i<n-1;i++)
            {
                if(board[i][0]=='O' && !vis[i][0])
                {
                    dfs(board,vis,n,m,i,0);
                }

                if(board[i][m-1]=='O' && !vis[i][m-1])
                {
                    dfs(board,vis,n,m,i,m-1);
                }
            }


            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(board[i][j]=='O' && vis[i][j]==false)
                    {
                        board[i][j]='X';
                    }
                }
            }
        }
        
    }
};
