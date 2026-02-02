class Solution {
private:
    //BFS approach
    void bfs(int i, vector<vector<int>>& adj, vector<int>& vis)
    {
        queue<int>q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it: adj[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    //DFS approach
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;    
        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                dfs(it,adj,vis);
            }
        }   
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<vector<int>>adj(n);

        vector<int>vis(n,0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bfs(i,adj,vis); 
                /* or we can do => 
                dfs(i,adj,vis) 
                
                both work for this problem*/
                count++;
            }
        }
        return count;
    }
};