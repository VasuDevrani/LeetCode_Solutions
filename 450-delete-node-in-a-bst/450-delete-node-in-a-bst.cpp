/**if()
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
    void getMax(TreeNode*root, int &max)
    {
        if(root->left == NULL)
        {
            max = root->val;
            return;
        }
        
        getMax(root->left, max);
    }
    
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(root == NULL)
            return NULL;
        
//         leaf node
        if(root->val == k && root->left == NULL && root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        
//         partial leaf nodes
        if(root->val == k && root->left == NULL)
        {
            TreeNode*temp = root->right;
            delete(root);
            return temp;
        }
        if(root->val == k && root->right == NULL)
        {
            TreeNode*temp = root->left;
            delete(root);
            return temp;
        }
        
//         non leaf nodes
        if(root->val == k)
        {
            int max = k;
            getMax(root->right, max);
            root->right = deleteNode(root->right, max);
            root->val = max;
            return root;
        }
        
        root->left = deleteNode(root->left, k);
        root->right = deleteNode(root->right, k);
        
        return root;
    }
};