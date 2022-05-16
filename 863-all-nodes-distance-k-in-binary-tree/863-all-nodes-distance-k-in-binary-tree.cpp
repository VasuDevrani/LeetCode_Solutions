/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void print_below(TreeNode*root, vector<int>&ans, int k)
    {
//         base case
        if(root==NULL)
            return;
        if(k==0)
        {
            ans.push_back(root->val);
            cout<<root->val<<3<<endl;
            return;
        }
        
//         recursive case
        print_below(root->left,ans,k-1);
        print_below(root->right,ans,k-1);
    }
    
    int find_distance(TreeNode*root, TreeNode*target, vector<int>&ans, int k)
    {
//         base case
        if(root==NULL)
            return -1;
        if(root==target)
        {
            print_below(root,ans,k);
            return 0;
        }
//         recursive case
        int dl=find_distance(root->left,target,ans,k);
        
        if(dl!=-1)
        {
            if(1+dl==k)
            {
                ans.push_back(root->val);
            }
            else
            {
                print_below(root->right,ans,k-dl-2);
                cout<<root->val<<1<<endl;
            }
            return dl+1;
        }
        int dr=find_distance(root->right,target,ans,k);
        
        if(dr!=-1)
        {
            if(1+dr==k)
            {
                ans.push_back(root->val);
                
            }
            else
            {
                print_below(root->left,ans,k-dr-2);
                cout<<root->val<<2<<endl;
            }
            return dr+1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        
        find_distance(root,target,ans,k);
        return ans;
    }
};