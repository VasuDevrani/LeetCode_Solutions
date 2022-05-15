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
        if(root==NULL)
            return 0;
        int x=height(root->left);
        int y=height(root->right);
        
        return max(x,y)+1;
    }
    
    void getsum(TreeNode*root,int &sum,int k)
    {
        if(root==NULL)
            return;
        if(k==1)
        {
            sum+=root->val;
            return;
        }
        
        getsum(root->left,sum,k-1);
        getsum(root->right,sum,k-1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        int sum=0;
        getsum(root,sum,h);
        
        return sum;
    }
};