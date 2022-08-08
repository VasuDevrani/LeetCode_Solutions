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
    
    class data{
        public:
        
        int mx;
        int mn;
        int diff;
        
        data(int a, int b, int c){
            mx = a;
            mn = b;
            diff = c;
        }
    };
    
    data getAns(TreeNode*root)
    {
//        base case
        if(root == NULL)
        {
            data d(0, 1000000, 0);
            return d;
        }
//         recursive case
        data d1 = getAns(root->left);
        data d2 = getAns(root->right);
        
        data d3(0, 0, 0);
        d3.mx = max(max(d1.mx, d2.mx), root->val);
        d3.mn = min(min(d1.mn, d2.mn), root->val);
        
        d3.diff = max(max(max(root->val - d1.mn, d1.mx - root->val), max(root->val - d2.mn, d2.mx - root->val)), max(d1.diff, d2.diff));
        
        return d3;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        data d = getAns(root);
        
        return d.diff;
    }
};