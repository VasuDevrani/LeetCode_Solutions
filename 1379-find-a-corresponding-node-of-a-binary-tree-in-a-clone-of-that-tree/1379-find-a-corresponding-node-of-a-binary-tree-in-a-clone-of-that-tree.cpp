/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    void getans(TreeNode*o,TreeNode*cl,TreeNode*t,TreeNode*&ans)
    {
//         base case
        if(o==NULL)
            return;
        if(o==t)
        {
            ans=cl;
            return;
        }
        
//         recursive case
        getans(o->left,cl->left,t,ans);
        getans(o->right,cl->right,t,ans);
        
    }
    
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* cl, TreeNode* t) {
        TreeNode*ans=NULL;
        getans(o,cl,t,ans);
        
        return ans;
    }
};