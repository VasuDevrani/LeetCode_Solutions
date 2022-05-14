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
    
    class tree
{
    public:
    bool a;
    int h;
};
    
    tree check_balanced(TreeNode*root)
{
    // base case
    if(root==NULL)
    {
        tree t;
        t.a=true;
        t.h=0;
        return t;
    }

    // recursive case
    tree t1=check_balanced(root->left);
    tree t2=check_balanced(root->right);

    tree tans;
    tans.h=max(t1.h,t2.h)+1;

    if(abs(t2.h-t1.h)<=1 && t1.a==true && t2.a==true)
    tans.a=true;
    else
    tans.a=false;

    return tans;
}
    
    bool isBalanced(TreeNode* root) {
        tree ans=check_balanced(root);
        return ans.a;
    }
};