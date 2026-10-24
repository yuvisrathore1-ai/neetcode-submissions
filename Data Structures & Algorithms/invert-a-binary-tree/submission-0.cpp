class Solution {
    TreeNode* dfs(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* lChild=dfs(root->left);
        TreeNode* rChild=dfs(root->right);

        root->left=rChild;
        root->right=lChild;

        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};
