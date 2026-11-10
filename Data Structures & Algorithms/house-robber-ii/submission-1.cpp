class Solution {
    int f(int idx,int end,vector<int>&nums,vector<int>&dp) {
        if(idx<end) return 0;
        if(idx==end) return nums[end];

        if(dp[idx]!=-1) return dp[idx];

        int notTake=0+f(idx-1,end,nums,dp);
        int take=0;
        take=nums[idx]+f(idx-2,end,nums,dp);

        return dp[idx] = max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        int amount1=f(n-1,1,nums,dp1);
        int amount2=f(n-2,0,nums,dp2);

        return max(amount1,amount2);
    }
};
