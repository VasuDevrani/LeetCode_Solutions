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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->right == NULL && root->left == NULL)
            return 1;
        int l = 1;
        int ans = 1;
        int mx = root->val;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        int sum = 0;
        while(!q.empty())
        {
            if(q.front() != NULL)
            {
                TreeNode*front = q.front();
                sum += front->val;
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            else
            {
                if(mx < sum)
                {
                    mx = sum;
                    ans = l;
                }
                sum = 0;
                l++;
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }
        }
        
        return ans;
    }
};