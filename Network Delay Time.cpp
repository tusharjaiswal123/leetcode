PROBLEM:


here are N network nodes, labelled 1 to N.
Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and
w is the time it takes for a signal to travel from source to target.
Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 
Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

1. N will be in the range [1, 100].
2. K will be in the range [1, N].
3. The length of times will be in the range [1, 6000].
4. All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.




SOLUTION:



class Solution {    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        int i,n,ans=INT_MIN;
        n=times.size();
        vector<pair<int,int>> adj[N+1];
        const int inf =1e9;
        vector<int> dist(N+1,inf);
        dist[K]=0;
        
        for(i=0;i<n;i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({0,K});
        
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            
            int s=p.second;
            
            for(auto k:adj[s])
            {   
                
                if(dist[k.first]>dist[s]+k.second)
                {
                    dist[k.first]=dist[s]+k.second;
                    pq.push({dist[k.first],k.first});
                }
            }
        }
        
        for(i=1;i<=N;i++)
        {
            if(dist[i]==inf)
                return -1;
            
            ans=max(ans,dist[i]);
        }
        
        return ans;
        
    }
};
