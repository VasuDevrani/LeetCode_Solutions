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
    vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        if(root == NULL)
            return v;
        if(root->left == NULL && root->right == NULL)
        {
            v.push_back(root->val);
            return v;
        }
        int max = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            if(q.front() != NULL)
            {
                TreeNode*front = q.front();
                if(front->val > max)
                    max = front->val;
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            else
            {
                v.push_back(max);
                max = INT_MIN;
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }
        }
        
        return v;
    }
};