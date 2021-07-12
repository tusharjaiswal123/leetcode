PROBLEM:


Given a string s, count the number of distinct, non-empty subsequences of s .
Since the result may be large, return the answer modulo 109 + 7.

Example 1:
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

Example 2:
Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".

Example 3:
Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 

Note:
1. s contains only lowercase letters.
2. 1 <= s.length <= 2000



SOLUTION:


class Solution {
public:
    int distinctSubseqII(string s) {
        
        int n,i,mod=1000000007;
        n = s.size();
        
        vector<int> dp(n+1);
        vector<int> last(26,-1);
        dp[0]=1;
        
        for(i=1;i<=n;i++)
        {
            dp[i] = (2*dp[i-1])%mod;
            
            if(last[s[i-1]-'a']!=-1)
                dp[i] = ((dp[i]-dp[last[s[i-1]-'a']-1])%mod+mod)%mod;
            
            last[s[i-1]-'a'] = i;
        }
        
        return dp[n]-1;
    }
};
