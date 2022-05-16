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
    
    void getSum(TreeNode*root,int &sum,int k)
    {
        if(root==NULL)
            return;
        if(k==0)
        {
            sum+=root->val;
            return;
        }
        
        getSum(root->left,sum,k-1);
        getSum(root->right,sum,k-1);
    }
    
    void trackEven(TreeNode*root,int &sum)
    {
//        base case
        if(root==NULL)
            return;
//         recursive case
        if(root->val%2==0)
            getSum(root,sum,2);
        trackEven(root->left,sum);
        trackEven(root->right,sum);
        
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        trackEven(root,sum);
        
        return sum;
    }
};