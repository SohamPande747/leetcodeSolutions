/* We se that each node is checked and 
that none of the nodes share the color 
with its neighboour 

If any single node shares a color with its neoghbour, 
we return false;

If we cannot find any such node, the the answer is true
*/

class Solution {
public:
    bool dfs(int node, int clr, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = clr;

        for (auto it: adj[node])
        {
            if (vis[it] == -1)
            {
                if(dfs(it, !clr, adj, vis) == false) return false;
            }
            else if (vis[it] == clr)
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>>adj(n+1);

        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }    
        
        vector<int>vis(n+1,-1);
        for (int i = 1; i < n; i++)
        {
            if (vis[i] == -1)
            {
                if (dfs(i,0,adj,vis) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};