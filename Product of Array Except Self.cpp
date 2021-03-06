PROBLEM:


Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the
elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits
in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space
complexity analysis.)



SOLUTION:



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int i,n,r;
        n=nums.size();
        
        vector<int> ans(n);
        
        ans[0]=1;
        
        for(i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        
        r=1;
        for(i=n-1;i>=0;i--)
        {
            ans[i]=ans[i]*r;
            r=r*nums[i];
        }
        
        return ans;
        
    }
};
