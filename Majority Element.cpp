PROBLEM:



Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2




SOLUTION:



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int idx,i,n,c;
        n=nums.size();
        
        idx=0;
        c=1;
        
        for(i=1;i<n;i++)
        {
            if(nums[idx]==nums[i])
                c++;
            else
                c--;
            
            if(c==0)
            {
                idx=i;
                c=1;
            }
        }
        
        return nums[idx];
    }
};
