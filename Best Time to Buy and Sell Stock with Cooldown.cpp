PROBLEM:



Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share
of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]


SOLUTION:



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i,n,t_ik0=0,t_ik1=INT_MIN,t_ik0_pre=0;
        n=prices.size();
        
        
        for(i=0;i<n;i++)
        {
            int t_ik0_old=t_ik0;
            
            t_ik0=max(t_ik0,t_ik1 + prices[i]);
            t_ik1=max(t_ik1,t_ik0_pre-prices[i]);
            
            t_ik0_pre = t_ik0_old;
        }
        
        return t_ik0;
        
        
    }
};
