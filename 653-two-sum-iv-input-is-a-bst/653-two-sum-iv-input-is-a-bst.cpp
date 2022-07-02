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
    
    bool traverseTree(TreeNode*root, unordered_map<int,int>&m, int k)
    {
        if(root == NULL)
            return false;
        
        bool a = traverseTree(root->left, m, k);
        
        if(m.find(k - root->val) != m.end())
            return true;
        m[root->val]++;
        
        bool b = traverseTree(root->right, m, k);
        return a | b;
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>m;
        
        return traverseTree(root, m, k);
    }
};