PROBLEM:



Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
We repeatedly make duplicate removals on S until we no longer can.
Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 
Example 1:
Input: "abbaca"
Output: "ca"

Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is
"aaca", of which only "aa" is possible, so the final string is "ca".
 
Note:
1. 1 <= S.length <= 20000
2. S consists only of English lowercase letters.




SOLUTION:


class Solution {
public:
    string removeDuplicates(string S) {
        
       int i,n;
        n = S.size();
        string ans; //stack
        
        for(i=0;i<n;i++)
        {
            if(ans.empty())
                ans.push_back(S[i]);
            else
            {
                if(S[i]==ans.back())
                    ans.pop_back();
                else
                    ans.push_back(S[i]);
            }
                
        }
        
        return ans;
    }
};
