/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        ListNode *f=NULL,*s=NULL,*prev=NULL;
        f = s = head;
        
        // find the middle element
        while(f!= NULL && f->next!=NULL){
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        if(prev==NULL){
            TreeNode* newNode = new TreeNode(s->val);
            return newNode;
        }
        
        //split the list
        prev->next = NULL;
        f = s->next;
        s->next = NULL;
        
        //Build the subtree
        TreeNode* temp = new TreeNode(s->val);
        temp->left = sortedListToBST(head);
        temp->right = sortedListToBST(f);
        
        return temp;
    }
};