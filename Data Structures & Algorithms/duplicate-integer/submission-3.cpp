class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>st;
        if(n==0) return false;
        st.insert(nums[0]);

        for(int i=1;i<n;i++) {
            int x=nums[i];
            if(st.count(x)) return true;
            st.insert(x);
        }

        return false;
    }
};