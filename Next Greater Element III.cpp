PROBLEM:




Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n.
If no such positive integer exists, return -1.
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 
Example 1:
Input: n = 12
Output: 21


Example 2:
Input: n = 21
Output: -1
 

Constraints:
1. 1 <= n <= 231 - 1



SOLUTION:



class Solution {
public:
    
    string next_permutation(string &s)
    {
        int i,n;
        n = s.size();
        i = n-2;
        
        while(i>=0 && s[i]>=s[i+1])
            i--;
        
        if(i==-1)
            return s;
        
        reverse(s.begin()+i+1,s.end());
        
        for(int j=i+1;j<n;j++)
        {
            if(s[j]>s[i])
            {
                swap(s[i],s[j]);
                break;
            }
        }
        
        return s;
        
    }

    int nextGreaterElement(int n) {
        
        int ans;
        string s;
        s = to_string(n);
        
        ans = stoll(next_permutation(s));

        if(ans<=INT_MAX && ans>n)
            return ans;
        
        return -1;
        
    }
};
