class Solution {
  public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& adj)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it,vis,pathvis,adj) == true) return true;
            }
            else if (pathvis[it] == 1)
            {
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) 
    {
        // code here
        vector<vector<int>>adj(V);
        vector<int>pathvis(V,0);
        vector<int>vis(V,0);
        
        
        for (auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i,vis,pathvis,adj) == true) return true;
            }
        }
        return false;
    }
};