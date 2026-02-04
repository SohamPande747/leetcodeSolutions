class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        // code here
        vector<int>indegree(V,0);
        vector<int>adj[V];
        
        for (auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int>q;
        
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for (auto it: adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};