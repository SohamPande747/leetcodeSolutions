class Solution {
public:
    //MERHOD 2:- DFS METHOD (RECURSIVE)
    bool dfs(int node, vector<vector<int>>& adj, vector<int>&vis, vector<int>& pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it,adj,vis,pathvis))
                    return true;
            }
            else if (pathvis[it])
            {
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(V);
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);

        for (auto it: edges)
        {
            adj[it[1]].push_back(it[0]);
        }    

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj,vis,pathvis) == true)
                {
                    return false;//cycle detected
                }
            }
        }
        return true;//no cycle
    }
};