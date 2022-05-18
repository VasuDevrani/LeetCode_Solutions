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
    
    TreeNode*getTree(vector<int>nums,int s,int e)
    {
//         base case
        if(e-s==0)
            return NULL;
//         recursive case
        int mi;
        int max=INT_MIN;
        for(int i=s;i<e;i++)
        {
            if(max<nums[i])
            {
                max=nums[i];
                mi=i;
            }
        }
        TreeNode*root=new TreeNode(max);
        
        root->left=getTree(nums,s,mi);
        root->right=getTree(nums,mi+1,e);
        return root;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        TreeNode*root=getTree(nums,0,nums.size());
        return root;
    }
};