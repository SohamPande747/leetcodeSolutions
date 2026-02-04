class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& image,vector<vector<int>>&vis, 
                int color,int inclr)
    {
        int n = image.size();
        int m = image[0].size();
        vis[r][c] = 1;
        image[r][c] = color;
        int delrow[] = {0,1,0,-1};
        int delcol[] = {-1,0,1,0};

        for (int i = 0; i < 4; i++)
        {
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];

            if (nrow >= 0 && nrow < n && 
                ncol >= 0 && ncol < m && 
                image[nrow][ncol] == inclr && 
                vis[nrow][ncol] == 0)
                {
                    dfs(nrow,ncol,image,vis,color,inclr);
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();
        int inclr = image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));

        dfs(sr,sc,image,vis,color,inclr);  
        
        return image;  
    }
};