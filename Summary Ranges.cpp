PROBLEM:


Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

Example 2:
Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.



SOLUTION:



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        long long i,n,s,e;
        n=nums.size();
        
        vector<string> v;
        
        if(n==0)
            return v;
        
        for(i=0;i<n;i++)
        {
            s=nums[i];
            
            while(i+1<n && (nums[i]==nums[i+1]-1))
                i++;
            
            e=nums[i];
            
            if(s==e)
                v.push_back(to_string(s));
            else
                v.push_back(to_string(s) + "->" + to_string(e));
            
        }
   
        return v;
    }
};
