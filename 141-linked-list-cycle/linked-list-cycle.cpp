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
        ListNode* rabbit=head;
        ListNode* tortoise=head;
        while(rabbit!=NULL and rabbit->next!=NULL){
            rabbit=rabbit->next->next;
                tortoise=tortoise->next;
            if(rabbit==tortoise){
                return true;
            }
        }
        return false;
    }
};