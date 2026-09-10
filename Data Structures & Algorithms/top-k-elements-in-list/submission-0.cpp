class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mpp;

        for(int x : nums)  mpp[x]++;
        for(auto it : mpp) {
            int key=it.first;
            int val=it.second;
            pq.push({val,key});
            if(pq.size() > k) pq.pop();
        }

        vector<int>res;
        while(!pq.empty()) {
            auto it=pq.top();
            pq.pop();
            res.push_back(it.second);
        }

        return res;
    }
};
