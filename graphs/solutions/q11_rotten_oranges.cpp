class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));    

        queue<vector<int>>q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({i,j,0});
                }
            }
        }
        int time = 0;
        while (!q.empty())
        {
            int row = q.front()[0];
            int col = q.front()[1];
            int t = q.front()[2];

            q.pop();
            time = max(t,time);

            int delrow[] = {0,1,0,-1};
            int delcol[] = {1,0,-1,0};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && 
                    grid[nrow][ncol] == 1)
                    {
                        q.push({nrow,ncol, t+1});
                        vis[nrow][ncol] = 2;
                    }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] != 2)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};