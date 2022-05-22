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
    
    void changeTree(TreeNode*&root,int &ct)
    {
        if(root==NULL)
            return;
        
        changeTree(root->right,ct);
        root->val=ct+root->val;
        ct=root->val;
        changeTree(root->left,ct);

    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int ct=0;
        changeTree(root,ct);
        return root;
    }
};