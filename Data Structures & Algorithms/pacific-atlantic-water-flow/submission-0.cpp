class Solution {
    vector<int>delR={-1,0,1,0};
    vector<int>delC={0,1,0,-1};

    bool isValid(int r,int c,int n,int m) {
        return r>=0 && r<n && c>=0 && c<m;
    }
    void dfs(int r,int c,int &n,int &m,vector<vector<int>>&vis,vector<vector<int>>&mat) {
        vis[r][c]=1;
        for(int i=0;i<4;i++) {
            int nr=r+delR[i];
            int nc=c+delC[i];
            if(isValid(nr,nc,n,m) && !vis[nr][nc] && mat[nr][nc]>=mat[r][c]) {
                dfs(nr,nc,n,m,vis,mat);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>vis1(n,vector<int>(m,0));
        vector<vector<int>>vis2(n,vector<int>(m,0));

        for(int i=0;i<n;i++)  {
            if(!vis1[i][0]) dfs(i,0,n,m,vis1,heights);
            if(!vis2[i][m-1]) dfs(i,m-1,n,m,vis2,heights);
        }
        for(int j=0;j<m;j++) {
            if(!vis1[0][j]) dfs(0,j,n,m,vis1,heights);
            if(!vis2[n-1][j]) dfs(n-1,j,n,m,vis2,heights);
        }

        vector<vector<int>>res;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis1[i][j] && vis2[i][j]) {
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
