PROBLEM:



Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical
order among all possible results.
Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/


Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:
1. 1 <= s.length <= 104
2. s consists of lowercase English letters.


OR


Return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/


Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"
 
Constraints:
1. 1 <= s.length <= 1000
2. s consists of lowercase English letters.







SOLUTION:



class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int i,n;
        n=s.size();
        
        vector<int> v(26,0);
        vector<bool> vis(26,false);
        string res="";
        
        for(i=0;i<n;i++)
            v[s[i]-'a']++;
        
        for(i=0;i<n;i++)
        {
            v[s[i]-'a']--;
            if(res.empty())
            {
                res.push_back(s[i]);
                vis[s[i]-'a']=true;
                continue;
            }
            
            if(vis[s[i]-'a'])
                continue;
            
            while(s[i]<res.back() && !res.empty() && v[res.back()-'a']>0)
            {   
                vis[res.back()-'a']=false;
                res.pop_back();   
            }
            
            vis[s[i]-'a']=true;
            res.push_back(s[i]);
        }
        
        return res;
        
    }
};
