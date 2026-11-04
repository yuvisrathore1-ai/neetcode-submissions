class Solution {
    bool f(int idx,int sum,vector<int>&nums,vector<vector<int>>&dp) {
        if(sum==0) return true;
        if(idx==0) {
            return nums[idx]==sum;
        }

        if(dp[idx][sum]!=-1) return dp[idx][sum];

        bool notTake=f(idx-1,sum,nums,dp);
        bool take=false;
        if(nums[idx]<=sum)take=f(idx-1,sum-nums[idx],nums,dp);

        return dp[idx][sum] = take||notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int ts=0;
        for(int x : nums)ts+=x;
        if(ts%2==1) return false;
        int sum=ts/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,nums,dp);
    }
};
