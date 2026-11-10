class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>inD(n,0);

        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            inD[it[0]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++) {
            if(inD[i]==0) q.push(i);
        }

        int completed=0;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            completed++;
            for(auto adjNode : adj[node]) {
                inD[adjNode]--;
                if(inD[adjNode]==0) q.push(adjNode);
            }
        }

        return completed==n;
    }
};
