/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ListNode* rabbit=head;
        // ListNode* tortoise=head;
        // while(rabbit!=NULL and rabbit->next!=NULL){
        //     if(rabbit==tortoise){
        //         return true;
        //     }
        //     else{
        //         rabbit=rabbit->next->next;
        //         tortoise=tortoise->next;
        //     }
        // }
        // return false;
        ListNode *slow,*fast;
        slow=head;
        fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                return true;
            }
            head=head->next;
        }
            return false;
    }
};