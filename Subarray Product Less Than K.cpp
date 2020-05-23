PROBLEM:



Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

1. 0 < nums.length <= 50000.
2. 0 < nums[i] < 1000.
3. 0 <= k < 10^6.




SOLUTION:



class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int i,j,n,ans=0;
        n=nums.size();
    
        long long p=1;
        
        j=0;
        for(i=0;i<n;i++)
        {
            p=p*nums[i];
            
            while(p>=k)
            {   
                p=p/nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        
    
        return ans;
        
    }
};
