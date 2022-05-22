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
    
    void getArr(TreeNode*root,vector<int>&arr)
    {
        if(root==NULL)
            return;
        
        getArr(root->left,arr);
        arr.push_back(root->val);
        getArr(root->right,arr);
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        // getting sorted array by inorder traversal of bst
        vector<int>arr;
        getArr(root,arr);
        
        int min=INT_MAX;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]-arr[i]<min)
                min=arr[i+1]-arr[i];       
        }
        
        return min;
    }
};