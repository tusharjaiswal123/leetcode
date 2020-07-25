PROBLEM:



Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
You may assume no duplicate exists in the array.

Example 1:
Input: [3,4,5,1,2] 
Output: 1


Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0




SOLUTION:


class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n,i,l,h,mid,ans,e;
        n=nums.size();
        
        l=0;
        h=n-1;
        e=nums[h];
        
        while(l<=h)
        {
            mid=l+(h-l)/2;
            
            if(nums[mid]<=e)
            {
                ans=nums[mid];
                h=mid-1;
            }
            else if(nums[mid]>e)
                l=mid+1;
        }
        
        return ans;
    }
};
