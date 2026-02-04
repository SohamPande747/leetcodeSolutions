class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis)
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
                grid[nrow][ncol] == '1')
                {
                    dfs(nrow,ncol,grid,vis);
                }
        }   
        return;
    }

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis)
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
                    grid[nrow][ncol] == '1')
                    {
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
            }   
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == 0)
                {
                    bfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};