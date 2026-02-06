class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>adj(V);

        vector<int>indegree(V,0);

        for (auto it: prerequisites)
        {
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }   

        queue<int>q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (auto it:adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return (count == V);
    }
};
