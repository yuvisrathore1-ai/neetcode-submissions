class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>>pq;

        for(int i=0;i<n;i++) {
            int x=points[i][0];int y=points[i][1];
            pq.push({x*x+y*y,{x,y}});
            if(pq.size()>k) {
                pq.pop();
            }
        }

        vector<vector<int>>res;
        while(!pq.empty()) {
            auto it=pq.top();
            pq.pop();
            int x=it.second.first;
            int y=it.second.second;
            res.push_back({x,y});
        }

        return res;
    }
};
