class Solution {
    static bool cmp(vector<int>&v1,vector<int>&v2) {
        return v1[1]<v2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);

        int lastEndTime=intervals[0][1];
        int cnt=1;
        for(int i=1;i<n;i++) {
            if(intervals[i][0]>=lastEndTime) {
                cnt++;
                lastEndTime=intervals[i][1];
            }
        }

        return n-cnt;
    }
};
