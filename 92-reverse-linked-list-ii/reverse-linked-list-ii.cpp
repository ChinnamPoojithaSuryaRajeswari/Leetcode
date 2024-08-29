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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int lngt = 0;
        ListNode* lft = head;
        while(lft){
            lngt+=1;
            if(lngt == left-1){
                break;
            }
            lft = lft->next;
        }
        ListNode* rgt = head;
        lngt=0;
        while(rgt){
            lngt+=1;
            if(lngt == right){
                break;
            }
            rgt = rgt->next;
        }
        ListNode* LowerBound ;
        if(lft == NULL){
            LowerBound = head;
        }
        else{
            LowerBound = lft->next;
        }
        ListNode* UpperBound = rgt;
        rgt = rgt->next;
        UpperBound->next = NULL;
        ListNode * hdd=LowerBound;
        while(LowerBound->next){
            ListNode*  req = LowerBound->next;
            LowerBound->next = LowerBound->next->next;
            req->next = hdd;
            hdd = req;
        }
        if(lft!=NULL){
            lft->next = hdd;
            LowerBound->next = rgt;
        }
        else{
            LowerBound->next = rgt;
            return hdd;
        }
        return head;
    }
};