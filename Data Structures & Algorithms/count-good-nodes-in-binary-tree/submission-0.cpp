class Solution {
    void dfs(TreeNode* root,int mx,int &cnt) {
        if(!root) return ;

        if(root->val >= mx) cnt++;
        mx=max(mx,root->val);

        dfs(root->left,mx,cnt);
        dfs(root->right,mx,cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int mx=root->val;
        int cnt=0;
        dfs(root,mx,cnt);
        return cnt;
    }
};
