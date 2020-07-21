PROBLEM:


Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:
1. board and word consists only of lowercase and uppercase English letters.
2. 1 <= board.length <= 200
3. 1 <= board[i].length <= 200
4. 1 <= word.length <= 10^3





SOLUTION:



class Solution {
    private:
    int n,m,k;
public:
        
    bool dfs(vector<vector<char>> &board,string word,int x,int y,int s)
    {   
        if(s==k)
            return true;
        
        if(x<0 || y<0 || x>=n || y>=m || board[x][y]!=word[s])
            return false;
        
        
        char curr=board[x][y];
        board[x][y]='*';
        
        if(dfs(board,word,x+1,y,s+1) || dfs(board,word,x-1,y,s+1) || dfs(board,word,x,y+1,s+1) ||
          dfs(board,word,x,y-1,s+1) )
            return true;
        
        board[x][y]=curr;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int i,j;
        n=board.size();
        m=board[0].size();
        
        k=word.size();
        
        if(n==0 || m==0)
            return false;
        
        if(k==0)
            return true;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        
        return false;
    }
};
