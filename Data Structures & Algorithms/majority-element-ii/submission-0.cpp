class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();

        int e1=-1;
        int e2=-1;
        int cnt1=0;int cnt2=0;

        for(int i=0;i<n;i++) {
            if(cnt1==0 and e2!=nums[i]) {
                cnt1=1;
                e1=nums[i];
            }
            else if(cnt2==0 and e1!=nums[i]) {
                cnt2=1;
                e2=nums[i];
            }
            else if(e1==nums[i]) cnt1++;
            else if(e2==nums[i]) cnt2++;
            else {
                cnt1--;cnt2--;
            }
        }

        cnt1=0;cnt2=0;
    
        for(int i=0;i<n;i++) {
            if(nums[i]==e1) cnt1++;
            else if(nums[i]==e2) cnt2++;
        }

        vector<int>lis;

        if(cnt1>n/3) lis.push_back(e1);
        if(cnt2>n/3) lis.push_back(e2);

        sort(lis.begin(),lis.end());
        return lis;
    }
};