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
    
    void getAns(TreeNode*root,int i,int &max,int &ans)
    {
        if(root==NULL)
            return;
        if(max<i){
            max=i;
            ans=root->val;
    }
        
        getAns(root->left,i+1,max,ans);
        getAns(root->right,i+1,max,ans);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        int max=0;
        getAns(root,1,max,ans);
        
        return ans;
    }
};