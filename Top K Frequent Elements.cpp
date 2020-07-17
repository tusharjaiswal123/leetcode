PROBLEM:



Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
1. You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
2. Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
3. It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
4. You can return the answer in any order.




SOLUTION:(unordered_map + min heap)



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        
        for(auto u:nums)
        {
            m[u]++;
        }
        
        for(auto u:m)
        {
            if(pq.size()<k)
            {
                pq.push({u.second,u.first});
            }
            else
            {
                if(pq.top().first<u.second)
                {
                    pq.pop();
                    pq.push({u.second,u.first});
                }
            }
        }
        
        while(!pq.empty())
        {
            auto v=pq.top();
            pq.pop();
            
            ans.push_back(v.second);
        }
        
        return ans;
        
    }
};
