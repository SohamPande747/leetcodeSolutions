class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>>q;
        int inclr = image[sr][sc];
        image[sr][sc] = color;

        vector<vector<int>>vis(n,vector<int>(m,0));

        q.push({sr,sc});

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            int delrow[] = {0,1,0,-1};
            int delcol[] = {1,0,-1,0};

            for (int i = 0; i < 4; i++)
            {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];

                if (nrow >= 0 && nrow < n && 
                    ncol >= 0 && ncol < m && 
                    image[nrow][ncol] == inclr && 
                    vis[nrow][ncol] == 0)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};