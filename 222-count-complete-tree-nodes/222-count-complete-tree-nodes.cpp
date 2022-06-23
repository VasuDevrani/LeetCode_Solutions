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
    
    void getAns(TreeNode*root, int &ct)
    {
        if(root == NULL)
            return;
        ct++;
        getAns(root->left, ct);
        getAns(root->right, ct);
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ct = 0;;
        getAns(root, ct);
        
        return ct;
    }
};