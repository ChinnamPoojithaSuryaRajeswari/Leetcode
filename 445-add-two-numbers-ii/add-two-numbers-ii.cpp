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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* hd1 = NULL;
        ListNode* hd2 = NULL;
        ListNode* traverse = l1;
        while(traverse){
            ListNode* NN = new ListNode(traverse->val);
            if(hd1==NULL){
                hd1 = NN;
            }
            else{
                NN->next = hd1;
                hd1 = NN;
            }
            traverse = traverse->next;
        }
        traverse = l2;
        while(traverse){
            ListNode* NN = new ListNode(traverse->val);
            if(hd2==NULL){
                hd2 = NN;
            }
            else{
                NN->next = hd2;
                hd2 = NN;
            }
            traverse = traverse->next;
        }
        ListNode* res = NULL;
        ListNode* temp;
        while(hd1 and hd2){
            ListNode* NN ;
            if(hd1->val+hd2->val+carry < 10){
                NN = new ListNode(hd1->val+hd2->val+carry);
                carry=0;
            }
            else{
                int p = hd1->val+hd2->val+carry;
                NN = new ListNode(p%10);
                p=p/10;
                carry=p;
            }
            if(res==NULL){
                res = NN;
                temp = NN;
            }
            else{
                temp->next = NN;
                temp = temp->next;
            }
            hd1 = hd1->next;
            hd2 = hd2->next;
        }
        while(hd1){
            ListNode* NN ;
            if(hd1->val+carry < 10){
                NN = new ListNode(hd1->val+carry);
                carry = 0;
            }
            else{
                int p = hd1->val+carry;
                NN = new ListNode(p%10);
                p=p/10;
                carry=p;
            }
            if(res==NULL){
                res = NN;
                temp = NN;
            }
            else{
                temp->next = NN;
                temp = temp->next;
            }
            hd1 = hd1->next;
        }
        while(hd2){
            ListNode* NN ;
            if(hd2->val+carry < 10){
                NN = new ListNode(hd2->val+carry);
                carry=0;
            }
            else{
                int p = hd2->val+carry;
                NN = new ListNode(p%10);
                p=p/10;
                carry=p;
            }
            if(res==NULL){
                res = NN;
                temp = NN;
            }
            else{
                temp->next = NN;
                temp = temp->next;
            }
            hd2 = hd2->next;
        }
        if(carry){
            ListNode* NN = new ListNode(carry);
            if(res==NULL){
                res = NN;
                temp = NN;
            }
            else{
                temp->next = NN;
                temp = temp->next;
            }
        }
        ListNode* finlres = NULL;
        while(res){
            ListNode* NN = new ListNode(res->val);
            if(finlres==NULL){
                finlres = NN;
            }
            else{
                NN->next = finlres;
                finlres = NN;
            }
            res = res->next;
        }
        return finlres;
    }
};