PROBLEM:



Given a binary string s and an integer k.
Return True if every binary code of length k is a substring of s. Otherwise, return False.

Example 1:
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.

Example 2:
Input: s = "00110", k = 2
Output: true

Example 3:
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Example 4:
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.

Example 5:
Input: s = "0000000001011100", k = 4
Output: false
 
Constraints:
1. 1 <= s.length <= 5 * 10^5
2. s consists of 0's and 1's only.
3. 1 <= k <= 20
  
  
  

SOLUTION:



class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n,i,j,hash;
        n = s.size();
        set<int> st;
        
        if(k>n)
            return false;
        
        for(i=0;i+k-1<n;i++)
        {   
            hash=0;
            for(j=0;j<k;j++)
            {   
                hash = (hash<<1);
                if(s[i+j]=='1')
                    hash |= 1;
            }
       
            st.insert(hash);
        }
        
        return st.size()==(1<<k);
    }
};
