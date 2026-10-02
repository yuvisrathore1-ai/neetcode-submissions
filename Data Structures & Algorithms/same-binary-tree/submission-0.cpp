class Solution {
    bool dfs(TreeNode*p,TreeNode*q) {
        if(p==nullptr && q==nullptr) return true;
        if(!p || !q) return false;
        if(p->val!=q->val) return false;

        return dfs(p->left,q->left) && dfs(p->right,q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        return dfs(p,q);
    }
};
