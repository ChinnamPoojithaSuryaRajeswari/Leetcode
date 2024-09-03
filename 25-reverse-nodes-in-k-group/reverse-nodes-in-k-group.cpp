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
    ListNode* reverseKGroup(ListNode* head, int k) {
       int len = 0,flag=0,lngt=0;
        ListNode* temp  = head;
        ListNode* tea = head;
        ListNode* res = head;
        while(temp){
            temp = temp->next;
            lngt+=1;
        }
        temp = head;
        lngt = lngt - (lngt%k);
        lngt-=1;
        k-=1;
        while(lngt){
            lngt-=1;
            if(temp->next == NULL) return head;
            if(len<k){
                len+=1;
                ListNode* NN = temp->next;
                temp->next = temp->next->next;
                NN->next = res;
                res = NN;
                if(flag==0){
                    head=NN;
                }
                else{
                    tea->next = NN;
                }
            }
            else{
                flag = 1;
                len=0;
                tea = temp;
                res = temp->next;
                temp =temp->next;
            }
            if(temp == NULL) return head;
        }
        return head;
    }
};