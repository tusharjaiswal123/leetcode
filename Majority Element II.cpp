PROBLEM:



Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.

Example 1:
Input: [3,2,3]
Output: [3]

Example 2:
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]




SOLUTION:



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int i,n,c1=0,c2=0,e1=-1,e2=-1;
        n=nums.size();
        vector<int> ans;
        
        for(i=0;i<n;i++)
        {
            if(nums[i]==e1)
                c1++;
            else if(nums[i]==e2)
                c2++;
            else if(c1==0)
            {
                e1=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                e2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        c1=c2=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]==e1)
                c1++;
            
            if(nums[i]==e2)
                c2++;
        }
    
        if(c1>(n/3))
        {
            ans.push_back(e1);
        }
        
        if(c2>(n/3))
            ans.push_back(e2);
        
        
        return ans;
        
    }
};
