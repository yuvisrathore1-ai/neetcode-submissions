class Solution {
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int left=dfs(root->left);
        int right=dfs(root->right);

        return 1+max(left,right);
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
