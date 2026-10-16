class Solution {
    void dfs(int node,vector<int>&vis,int &cntNode,int &degree,vector<vector<int>>&adj) {
        vis[node]=1;
        cntNode++;
        for(auto it : adj[node]) {
            degree++;
            if(!vis[it]) {
                dfs(it,vis,cntNode,degree,adj);
            }
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(n,0);
        int degree=0;int cntNodes=0;

        dfs(0,vis,cntNodes,degree,adj);
        if(cntNodes < n) return false;
        int edgesCnt=degree/2;
        return edgesCnt==n-1; 
    }
};
