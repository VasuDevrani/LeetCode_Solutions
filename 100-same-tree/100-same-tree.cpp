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
    
    void track(TreeNode*root,vector<int>&v)
    {
//         base case
        if(root==NULL)
        {
            v.push_back(-1);
            return;
        }
        
//         recursive case
        v.push_back(root->val);
        track(root->left,v);
        track(root->right,v);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v1;
        vector<int>v2;
        
        track(p,v1);
        track(q,v2);
        
        if(v1==v2)
            return true;
        else
            return false;
    }
};