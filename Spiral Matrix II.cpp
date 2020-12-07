PROBLEM:



Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]


Example 2:
Input: n = 1
Output: [[1]]
 

Constraints:
1. 1 <= n <= 20





SOLUTION:


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int i,l1,l2,r1,r2,c;
        vector<vector<int>> v(n,vector<int>(n));
        
        l1=0;
        l2=n-1;
        r1=0;
        r2=n-1;
        c=1;
        
        while(l1<=l2 && r1<=r2)
        {   
        
            for(i=l1;i<=l2;i++)  //left to right
                v[r1][i]=c++;
        
            
            for(i=r1+1;i<=r2;i++) //top to down
                v[i][l2]=c++;

            
            for(i=l2-1;i>=l1;i--)  //right to left
                v[r2][i]=c++;
         
            
            for(i=r2-1;i>r1;i--)  //down to top
                v[i][l1]=c++;
          
            
            l1++;  
            l2--;
            r1++;
            r2--;
        }
        
        return v;
        
    }
};
