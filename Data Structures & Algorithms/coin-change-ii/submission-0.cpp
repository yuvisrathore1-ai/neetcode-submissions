class Solution {
    int f(int idx,int sum,vector<int>&coins,vector<vector<int>>&dp) {
        if(sum==0) return 1;
        if(idx<0) return 0;
        if(idx==0) {
            if(sum%coins[idx]==0) return 1;
            else return 0;
        }

        if(dp[idx][sum]!=-1) return dp[idx][sum];

        int notTake=0 + f(idx-1,sum,coins,dp);
        int take=0;
        if(coins[idx]<=sum) take=f(idx,sum-coins[idx],coins,dp);

        return dp[idx][sum] = take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return f(n-1,amount,coins,dp);
    }
};
