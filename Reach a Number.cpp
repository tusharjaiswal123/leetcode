PROBLEM:




You are standing at position 0 on an infinite number line. There is a goal at position target.
On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.
Return the minimum number of steps required to reach the destination.


Example 1:
Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.

Example 2:
Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.

Note:
1. target will be a non-zero integer in the range [-10^9, 10^9].






SOLUTION:




class Solution {
public:
    int reachNumber(int target) {
        
        int ans=0,i=0;
        
        target = abs(target);
        
        while(target>( (i*(i+1))/2))
        {    
            i++;
            ans++;
        }
        
        if(target==((i*(i+1))/2))
            return ans;
        
        while( (((i*(i+1))/2) - target)%2!=0)
        {
            ans++;
            i++;
        }
        
        
        return ans;
        
    }
};
