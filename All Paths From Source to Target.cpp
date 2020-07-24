PROBLEM:



Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Note:
1. The number of nodes in the graph will be in the range [2, 15].
2. You can print different paths in any order, but you should keep the order of nodes inside one path.





SOLUTION:




class Solution {
    private:
    
    int n;
    vector<vector<int>> ans;
    
public:
    
    void dfs(vector<vector<int>> &graph,vector<bool> &vis,vector<int> &v,int s)
    {   
        v.push_back(s);
        vis[s]=true;
        
  
        if(s==n-1)
        {   
            ans.push_back(v);
        }
        
        for(auto u:graph[s])
        {
            if(!vis[u])
                dfs(graph,vis,v,u);
        }
        
        v.pop_back();
        vis[s]=false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int i,j;
        n=graph.size();
        
        vector<bool> vis(n,false);
        vector<int> v;
        ans.clear();
        v.clear();
    
        
        dfs(graph,vis,v,0);
        
        return ans;
    }
};
