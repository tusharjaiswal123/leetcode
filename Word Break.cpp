PROBLEM:



Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or
more dictionary words.

Note:
1. The same word in the dictionary may be reused multiple times in the segmentation.
2. You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false





SOLUTION:



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n,i,j;
        n=s.size();
        
        set<string> st;
        vector<int> dp(n+1,false);
        dp[0]=true;
        
        for(auto k:wordDict)
            st.insert(k);
        
        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(dp[j])
                {
                    string w=s.substr(j,i-j);
                    
                    if(st.find(w)!=st.end())
                    {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
        
    }
};
