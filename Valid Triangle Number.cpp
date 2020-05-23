PROBLEM:



Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make
triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
1. The length of the given array won't exceed 1000.
2. The integers in the given array are in the range of [0, 1000].



SOLUTION:



class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int i,j,k,n,ans=0;
        n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(i=n-1;i>=0;i--)
        {
            j=0;
            k=i-1;
            
            while(j<k)
            {
                if(nums[j]+nums[k]>nums[i])
                {
                    ans += k-j;        // nums[k]+ (nums[j] + nums[j+1] + ... upto nums[k-1]) > nums[i]
                    k--;
                }
                else
                    j++;
            }
        }
        
        return ans;
    }
};
