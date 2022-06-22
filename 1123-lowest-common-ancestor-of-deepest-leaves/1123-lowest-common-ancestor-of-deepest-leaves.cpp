/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int height(TreeNode*root)
    {
        if(root == NULL)
            return 0;
        int x = height(root->left);
        int y = height(root->right);
        
        return max(x,y) + 1;
    }
    
    TreeNode*lca(TreeNode*root, int l, int h)
    {
        if(root == NULL)
            return NULL;
        if(l == h)
            return root;
        
        TreeNode*left = lca(root->left, l+1, h);
        TreeNode*right = lca(root->right, l+1, h);
        
        if(left != NULL && right != NULL)
            return root;
        else if(right == NULL)
            return left;
        else 
            return right;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h = height(root);
        return lca(root, 1, h);
    }
};