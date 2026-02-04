class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis)
    {
        int n = board.size();
        int m = board[0].size();

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

            for (int i = 0; i < 4;i++)
            {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];

                if (nrow >= 0 && nrow < n && 
                    ncol >= 0 && ncol < m && 
                    vis[nrow][ncol] == 0 && 
                    board[nrow][ncol] == 'O')
                    {
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
            }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O')
            {
                bfs(0,i,board,vis);
            }
            if (board[n-1][i] == 'O')
            {
                bfs(n-1,i,board,vis);
            }
        }    
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                bfs(i,0,board,vis);
            }
            if (board[i][m-1] == 'O')
            {
                bfs(i,m-1,board,vis);
            }
        }   

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};