class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector <vector<int>> res(n);
        vector <int> outdegree(n), safe(n), ans;

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            for (int v:graph[i])
            {
                res[v].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0) q.push(i);
        }       
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            safe[u] = 1;
            for (int v: res[u])
            {
                if (--outdegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (safe[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};