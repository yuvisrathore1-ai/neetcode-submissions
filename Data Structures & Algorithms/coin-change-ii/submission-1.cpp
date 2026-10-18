class Solution {
    int f(int idx,int sum,int &n, int &amount,vector<int>&coins,vector<vector<int>>&dp) {
        if(sum>amount) return 0;
        if(sum==amount) return 1;
        if(idx>n-1) return 0;
        if(idx==n-1) {
            if((amount-sum)%coins[n-1]==0) return 1;
            else return 0;
        }

        if(dp[idx][sum]!=-1) return dp[idx][sum];

        int notTake=f(idx+1,sum,n,amount,coins,dp);
        int take=0;
        if(sum+coins[idx]<=amount) take=f(idx,sum+coins[idx],n,amount,coins,dp);

        return dp[idx][sum] = take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return f(0,0,n,amount,coins,dp);
    }
};
