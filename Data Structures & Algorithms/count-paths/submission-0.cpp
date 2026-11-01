class Solution {
    bool isValid(int i,int j,int n,int m) {
        return i>=0 && i<n && j>=0 && j<m;
    }
    int f(int i,int j,int &n,int &m,vector<vector<int>>&dp) {
        if(!isValid(i,j,n,m)) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=f(i,j+1,n,m,dp);
        int down=f(i+1,j,n,m,dp);

        return dp[i][j] = right+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,m,dp);
    }
};
