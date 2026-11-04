class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int ts=0;
        for(int x : nums)ts+=x;
        if(ts%2==1) return false;
        ts=ts/2;
        vector<vector<bool>>dp(n,vector<bool>(ts+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=ts)dp[0][nums[0]]=true;

        for(int idx=1;idx<=n-1;idx++) {
            for(int sum=ts;sum>=0;sum--) {
                bool notTake=dp[idx-1][sum];
                bool take=false;
                if(nums[idx]<=sum)take=dp[idx-1][sum-nums[idx]];

                dp[idx][sum] = take||notTake;
            }
        }
        return dp[n-1][ts];
    }
};
