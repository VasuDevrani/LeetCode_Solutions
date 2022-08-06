/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// // explanation:
// the if condition is present at the first encounter of s & f pointers
// take l1 = distance between head and entry point
// take l2 = distance from entry point to encounter point
// take l3 = distance from encounter point to entry point

// as, distance of f = 2* distance of slow
//     l1+l2+l3+l2 = 2*(l1+l2)
//     l3 = l1
    
// this means that after the first encounter of s & f pointers, distance travelled by any pointer from head to entry point will be equal to l3
// or, after l3 travel of s and after l1 travel of any pointer from head, they meet at entry

// so simply run them until they become equal, they definitely will


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        
        ListNode*s = head;
        ListNode*f = head;
        
        while(f != NULL && f->next != NULL)
        {
            f = f->next->next;
            s = s->next;
            
            if(s == f)
            {
                f = head;
                while(f != s)
                {
                    f = f->next;
                    s = s->next;
                }
                return s;
            }
        }
        return NULL;
    }
};