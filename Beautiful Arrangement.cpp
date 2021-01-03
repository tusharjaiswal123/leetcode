PROBLEM:



Suppose you have n integers from 1 to n. We define a beautiful arrangement as an array that is constructed by these n numbers successfully if one of the following is true
for the ith position (1 <= i <= n) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:
Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1, 2]:
Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
The second beautiful arrangement is [2, 1]:
Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.


Example 2:
Input: n = 1
Output: 1
 
Constraints:
1. 1 <= n <= 15




SOLUTION:




class Solution {
public:
    
    void bk(int n,int i,vector<bool> &vis,int &ans)
    {
        if(i>n)
            ans++;
        
        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && (j%i==0 || i%j==0))
            {
                vis[j]=true;
                bk(n,i+1,vis,ans);
                vis[j]=false;
            }
        }
    }
    
    int countArrangement(int n) {
        
        int ans=0;
        vector<bool> vis(n+1,false);
        bk(n,1,vis,ans);
        
        return ans;
        
    }
};
