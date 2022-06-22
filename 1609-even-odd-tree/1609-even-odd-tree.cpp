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
    bool isEvenOddTree(TreeNode* root) {
        
        if(root == NULL)
            return true;
        int prev = INT_MIN, l = 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            if(q.front() != NULL)
            {
                TreeNode*front = q.front();
                q.pop();
                if(l&1)
                {
                    if(front->val & 1)
                        return false;
                    if(front->val >= prev)
                        return false;
                    else
                        prev = front->val;
                }
                else
                {
                    if((front->val & 1) == 0)
                        return false;
                    if(front->val <= prev)
                        return false;
                    else
                        prev = front->val;
                }
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            else
            {
                q.pop();
                l++;
                if(l&1)
                    prev = INT_MAX;
                else
                    prev = INT_MIN;
                if(!q.empty())
                    q.push(NULL);
            }
        }
        
        return true;
    }
};