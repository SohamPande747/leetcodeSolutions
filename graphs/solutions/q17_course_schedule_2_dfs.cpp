class Solution {
public: 
    //DFS Method
    bool dfs(int node, vector<vector<int>>& adj, vector<int>&vis, vector<int>& pathvis, stack<int>& st)
    {
   
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it,adj,vis,pathvis,st))
                    return true;
            }
            else if (pathvis[it])
            {
                return true;
            }
        }
        st.push(node);
        pathvis[node] = 0;
        return false;
    }
    vector<int> findOrder(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(V);
        vector<int>vis(V, 0);
        vector<int>pathvis(V, 0);
        stack<int>st;

        for (auto it: edges)
        {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, pathvis, st);
            }
        }
        vector<int>topo;

        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        if (topo.size() != V) return {};
        return topo;
    }
};