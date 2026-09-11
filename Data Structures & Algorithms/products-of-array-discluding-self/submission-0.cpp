class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>l(n,1) ,r(n,1);

        for(int i=0;i<n-1;i++) {
            l[i+1]=l[i]*nums[i];
            r[n-i-2]=nums[n-i-1]*r[n-i-1];
        }

        vector<int>res(n,1);
        for(int i=0;i<n;i++) {
            res[i]=r[i]*l[i];
        }

        return res;
    }
};
