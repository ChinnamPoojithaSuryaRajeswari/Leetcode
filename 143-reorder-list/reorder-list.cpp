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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* hd1 = NULL;
        int lengt=0;
        while(temp){
            ListNode* NN = new ListNode(temp->val);
            if(hd1 == NULL){
                hd1 = NN;
            }
            else{
                NN->next = hd1;
                hd1 = NN;
            }
            temp = temp->next;
            lengt+=1;
        }
        temp = head;
        while(lengt){
            lengt-=1;
            if(lengt==0){
                break;
            }
            ListNode* res;
            res = hd1;
            hd1=hd1->next;
            res->next  = temp->next;
            temp->next = res;
            lengt-=1;
            if(lengt == 0){
                temp = res;
            }
            else{
                temp=res->next; 
            }
            // cout<<lengt<<" ";
        }
        temp->next = NULL;
    }
};