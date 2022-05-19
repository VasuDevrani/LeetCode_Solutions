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
    
    void conversion(TreeNode*&root,TreeNode*&prev)
    {
//         base case
        if(root==NULL)
            return;
        
//         recursive case
        conversion(root->right,prev);
        conversion(root->left,prev);
        
        root->right=prev;
        root->left=NULL;
        prev=root;
        
    }
    
    void flatten(TreeNode* root) {
        TreeNode*prev=NULL;
        conversion(root,prev);
    }
};