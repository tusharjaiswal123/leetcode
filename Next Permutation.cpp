PROBLEM:


Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1



SOLUTION:


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i,n,j;
        n=nums.size();
        
        for(i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
                break;
                
        }
        
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
        }
        
        else
        {
            for(j=n-1;j>i;j--)
            {
                if(nums[j]>nums[i])
                    break;
            }
            
            swap(nums[j],nums[i]);
            reverse(nums.begin() + i + 1,nums.end());
        }
        
    }
};
