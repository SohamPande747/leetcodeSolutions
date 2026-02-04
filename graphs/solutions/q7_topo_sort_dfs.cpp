class Solution {
  public:   
    void dfs(int node, vector<vector<int>>&e, vector<int>&vis, stack<int>&st)
    {
        vis[node] = 1;
        
        for (auto it: e[node])
        {
            if (!vis[it])
            {
                dfs(it,e,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        // code here
        vector<vector<int>>adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>vis(V,0);
        stack<int>st;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i,adj,vis,st);
            }
        }
        vector<int>ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};