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
    
    void getAns(TreeNode* root, int l, int d, map<int,vector<pair<int,int>>>&m)
    {
        if(root == NULL)
            return;
        
        m[d].push_back(make_pair(l, root->val));
        
        getAns(root->left, l+1, d-1, m);
        getAns(root->right, l+1, d+1, m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<pair<int,int>>>m;
        
        vector<vector<int>>ans;
        
        getAns(root, 0, 0, m);
        
        for(auto x:m)
        {
            sort(x.second.begin(), x.second.end());
            
            vector<int>left;
            for(auto y:x.second)
                left.push_back(y.second);
            
            ans.push_back(left);
        }
        
        return ans;
    }
};