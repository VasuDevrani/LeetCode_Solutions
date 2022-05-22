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
    
    void fillNodes(TreeNode*root,int nodes[],int &ct)
    {
        if(root==NULL)
            return;
        
        fillNodes(root->left,nodes,ct);
        nodes[ct]=(root->val);
        ct++;
        fillNodes(root->right,nodes,ct);
    }
    
    TreeNode*buildTree(int nodes[],int s,int e)
    {
        if(s>e)
        return NULL;
        
        int mid=(s+e)/2;
        
        TreeNode*temp=new TreeNode(nodes[mid]);
        temp->left=buildTree(nodes,s,mid-1);
        temp->right=buildTree(nodes,mid+1,e);
        
        return temp;
    }
    
    TreeNode* balanceBST(TreeNode* root) 
    {
        int nodes[100000];
        int ct=0;
        fillNodes(root,nodes,ct);
        
        TreeNode*ans=buildTree(nodes,0,ct-1);
        
        return ans;
    }
};