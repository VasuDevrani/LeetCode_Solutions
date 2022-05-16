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
    
    void checkTree1(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            ans.push_back(-1);
            return;
        }
        
         ans.push_back(root->val);
        checkTree1(root->left,ans);
        checkTree1(root->right,ans);
    }
    
    void checkTree2(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            ans.push_back(-1);
            return;
        }
        
         ans.push_back(root->val);
        checkTree2(root->right,ans);
        checkTree2(root->left,ans);
        
    }
    
    bool isSymmetric(TreeNode* root) {
       
        vector<int>ans1;
        vector<int>ans2;
        checkTree1(root->right,ans2);
        checkTree2(root->left,ans1);

        if(ans1==ans2)
            return true;
        else
            return false;
    }
};