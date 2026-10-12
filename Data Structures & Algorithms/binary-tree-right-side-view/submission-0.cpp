class Solution {
    void dfs(TreeNode* root,int depth,map<int,int>&mpp) {
        if(!root) return;
        if(mpp.find(depth)==mpp.end()) {
            mpp[depth]=root->val;
        }
        dfs(root->right,depth+1,mpp);
        dfs(root->left,depth+1,mpp);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mpp;
        int depth=0;
        dfs(root,depth,mpp);

        vector<int>res;
        for(auto it : mpp) res.push_back(it.second);

        return res;
    }
};
