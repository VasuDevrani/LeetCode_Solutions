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
    class heid{
        public:
        int h;
        int d;
    };
    heid diameter(TreeNode* root)
    {
        //         base case
        if(root==NULL)
        {
            heid p;
            p.h=0;
            p.d=0;
            return p;
        }
        
//         recursive case
        heid left=diameter(root->left);
        heid right=diameter(root->right);
        
        heid p;
        p.h=max(left.h,right.h)+1;
        p.d=max(max(left.h+right.h,left.d),right.d);
        
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heid ans=diameter(root);
        return ans.d;
    }
};