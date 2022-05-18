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
    
    void getPaths(TreeNode*root,vector<string>&ans,string temp)
    {
//         base case
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }
        
//         recursive case
          temp += to_string(root->val);
          temp += "->";
        getPaths(root->left,ans,temp);
        getPaths(root->right,ans,temp);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        
        if(root==NULL)
            return ans;
        
        string temp="";
        getPaths(root,ans,temp);
        
        return ans;
    }
};