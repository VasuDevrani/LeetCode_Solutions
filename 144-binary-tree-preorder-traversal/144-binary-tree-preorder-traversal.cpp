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
    
    void inorder_print(TreeNode*root,vector<int>&ans)
    {
//         base
        if(root==NULL)
            return;
//         recursive 
         ans.push_back(root->val);
        inorder_print(root->left,ans);
        inorder_print(root->right,ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder_print(root,ans);
        
        return ans;
    }
};