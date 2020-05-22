PROBLEM:


Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the
sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.



SOLUTION:


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int i,j,n,ans=INT_MAX,sum=0;
        n=nums.size();
        
        j=0;
        for(i=0;i<n;i++)
        {
            sum = sum + nums[i];
            while(sum>=s)
            {   
                ans=min(ans,i-j+1);
                sum=sum-nums[j];
                j++;
            }
        
        }
        
        if(ans==INT_MAX)
            return 0;
        
        return ans;
        
    }
};
