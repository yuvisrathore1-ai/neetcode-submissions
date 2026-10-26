class Solution {
    TreeNode* dfs(TreeNode* root,TreeNode*&p,TreeNode*&q) {
        if(!root) return nullptr;
        int v=root->val;
        int x=p->val;int y=q->val;

        if(root==p || root==q) return root;

        if(x<v && y<v) return dfs(root->left,p,q);
        else if(x>v && y>v) return dfs(root->right,p,q);
        else return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};
