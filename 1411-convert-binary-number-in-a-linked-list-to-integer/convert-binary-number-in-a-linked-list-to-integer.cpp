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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int c=0,s=0;
        ListNode* temp=head;
        while(temp->next){
            c+=1;
            temp=temp->next;
        }
        temp = head;
        while(temp)
        {
            if(temp->val == 1)
            {
            s=s+(pow(2,c)*temp->val);
            }
            temp=temp->next;
            c-=1;
        }
        return s;
    }
};