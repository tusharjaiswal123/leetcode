PROBLEM:



There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest
price from src to dst with up to k stops. If there is no such route, output -1.


Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200


Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500

 
Constraints:

1. The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
2. The size of flights will be in range [0, n * (n - 1) / 2].
3. The format of each flight will be (src, dst, price).
4. The price of each flight will be in the range [1, 10000].
5. k is in the range of [0, n - 1].
6. There will not be any duplicated flights or self cycles.




SOLUTION:



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        const int inf=1e9;
        vector<pair<int,int>> adj[n];
        vector<bool> vis(n,false);
        vector<int> dis(n,inf);
        dis[src]=0;
        
        int i,m;
        m=flights.size();
        
        for(i=0;i<m;i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,src,K});
        
        while(!pq.empty())
        {   
            auto [d,s,K] = pq.top();
            pq.pop();
            
            if(s==dst)
                return d;
            
            if(K==-1)
            continue;
            
            for(auto k:adj[s])
            {
                pq.push({d+k.second,k.first,K-1});
            }
        }
        
        return -1;
        
    }
};
