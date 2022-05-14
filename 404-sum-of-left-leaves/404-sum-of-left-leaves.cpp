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
    
    void leftLeaf(TreeNode*root, int i,int &ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL && i==0)
        {
            ans+=root->val;
            cout<<root->val<<" ";
            return;
        }
        if(root->left==NULL && root->right==NULL && i==1)
            return;
        
        leftLeaf(root->left,0,ans);
        leftLeaf(root->right,1,ans);  
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        leftLeaf(root,1,ans);
        return ans;
    }
};