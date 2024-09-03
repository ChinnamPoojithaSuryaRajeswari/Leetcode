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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        if(head->next->next == NULL) return head;
        ListNode* temp = head;
        int len=0;
        while(temp->next->next){
            len+=1;
            temp = temp->next;
        } 
        ListNode* p ;
        ListNode* res = head;
        len=len+=2;
        if(len%2==1){
            temp = temp->next;
           p= NULL;
        len = len/2;
        }
        else{
           p = temp->next;
            len = len/2;
            len-=1;
        }
        while(len){
            ListNode* NN = res->next;
            res -> next = NN->next;
            NN->next = NULL;
            temp->next = NN;
            temp = temp->next;
            res = res->next;
            len-=1;
        }
        if(p!=NULL){
            temp->next = p;
            p->next = NULL;
        }
        return head;
    }
};