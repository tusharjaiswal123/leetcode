PROBLEM:



Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]

Note:
1. The total number of elements of the given matrix will not exceed 10,000.





SOLUTION:



class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        int i,j,r,c,k,n,m;
        vector<int> ans;
        
        n = matrix.size();
        if(n==0)
            return ans;
        
        m = matrix[0].size();
        stack<int> s;
        
        
        k=1;
        r=c=0;
        while(1)
        {   
            i = r;
            j = c;
            
            
            if(k%2==0)
            {
                while(i>=0 && i<n && j>=0 && j<m)
                {
                    ans.push_back(matrix[i][j]);
                    i++;
                    j--;
                }
            }
            else
            {   
                while(i>=0 && i<n && j>=0 && j<m)
                {
                    s.push(matrix[i][j]);
                    i++;
                    j--;
                }
                
                while(!s.empty())
                {
                    ans.push_back(s.top());
                    s.pop();
                }
            
            }
            
            k++;
            c++;
            
            
            if(c>=m)
            {
                c=m-1;
                r++;
            }
            
            if(r==n)
                break;
            
        }
        
        return ans;
        
    }
};
