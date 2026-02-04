class Solution {
public:
    //DFS 
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        int delrow[] = {0,1,0,-1};
        int delcol[] = {-1,0,1,0};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if (nrow >= 0 && nrow < n && 
                ncol >= 0 && ncol < m && 
                vis[nrow][ncol] == 0 && 
                grid[nrow][ncol] == 1)
            {
                dfs(nrow,ncol,grid,vis);
            }
        }
    }

    //BFS
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        queue<pair<int,int>>q;
        q.push({row,col});

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int delrow[] = {0,1,0,-1};
            int delcol[] = {-1,0,1,0};

            for (int i = 0; i < 4; i++)
            {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];

                if (nrow >= 0 && nrow < n && 
                    ncol >= 0 && ncol < m && 
                    vis[nrow][ncol] == 0 && 
                    grid[nrow][ncol] == 1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

    //either of the algorithms can be used 
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
            {
                dfs(i,0,grid,vis);
                //bfs(i,0,grid,vis);
            }
            
            if (grid[i][m-1] == 1)
            {
                dfs(i,m-1,grid,vis);
                //bfs(i,m-1,grid,vis);
            }
        }    

        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1)
            {
                dfs(0,i,grid,vis);
                //bfs(0,i,grid,vis);
            }
            
            if (grid[n-1][i] == 1)
            {
                dfs(n-1,i,grid,vis);
                //bfs(n-1,i,grid,vis);
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};