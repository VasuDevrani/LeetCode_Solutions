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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            if(q.front()!=NULL)
            {
                TreeNode*temp=q.front();
                q.pop();
                v.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else
            {
                ans.push_back(v);
                v.clear();
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};