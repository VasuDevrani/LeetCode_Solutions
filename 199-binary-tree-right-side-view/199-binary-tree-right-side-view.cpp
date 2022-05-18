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
    
    void getAns(TreeNode*node,int &maxl,int level,vector<int>&ans)
    {
        if(node==NULL)
            return;
        if(maxl<level)
        {
            ans.push_back(node->val);
            maxl=level;
        }
        
        getAns(node->right,maxl,level+1,ans);
        getAns(node->left,maxl,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        
        int maxl=0;
        ans.push_back(root->val);
        getAns(root,maxl,0,ans);
        
        return ans;
    }
};