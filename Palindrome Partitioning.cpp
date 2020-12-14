PROBLEM:



Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.


Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]


Example 2:
Input: s = "a"
Output: [["a"]]
 

Constraints:
1. 1 <= s.length <= 16
2. s contains only lowercase English letters.




SOLUTION:




class Solution {
public:
    
    void dfs(string &s,int n,int i,vector<vector<bool>> &dp,vector<string> &v,vector<vector<string>> &ans)
    {
        if(i>=n)
        {   
            ans.push_back(v);
            return;
        }
        
        for(int k=i;k<n;k++)
        {
            if(dp[i][k])
            {   
                v.push_back(s.substr(i,k-i+1));
                dfs(s,n,k+1,dp,v,ans);
                v.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        int i,j,n;
        n=s.size();
        vector<vector<string>> ans;
        vector<string> v;
        vector<vector<bool>> dp(n,vector<bool>(n,false));  //dp[i][j] represents whether substring
                                                          // s[i]...s[j] is palindrome or not                                                  
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(s[i] == s[j] && (i-j<=2 || dp[j+1][i-1]))
                    dp[j][i]=true;
            }
        }
        
        dfs(s,n,0,dp,v,ans);
        
        return ans;
        
    }
};
