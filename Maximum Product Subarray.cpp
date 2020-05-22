PROBLEM:


Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.



SOLUTION:


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int i,n,ans,current_min,current_max;
        n=nums.size();
            
        ans=nums[0];
        current_min=nums[0];
        current_max=nums[0];
        
        for(i=1;i<n;i++)
        {
            int a[]={nums[i],nums[i]*current_min,nums[i]*current_max};
            sort(a,a+3);
            
            current_min=a[0];
            current_max=a[2];
            
            ans=max(ans,current_max);
        }
        
        return ans;
    }
};
