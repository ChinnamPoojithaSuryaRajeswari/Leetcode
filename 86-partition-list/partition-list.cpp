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
    ListNode* partition(ListNode* head, int x) {
        ListNode* res = head;
        ListNode* req = head;
        if(head==NULL) return head;
        if(head->next == NULL) return head;
        if(res->val >=x){
            res = head;
        }
        else{
            while(res->next){
                if(res->next->val >= x){
                    break;
                }
                res = res->next;
            }
        }
        if(res->next == NULL){
            if(res->val < x){
                res = res->next;
            }
        }
        if(res == NULL) return head;
        else if(res->val < x){
            req = res;
            ListNode* temp=res;
            res = res->next;
            while(res){
                if(res->val < x){
                    ListNode* NN = new ListNode(res->val);
                    NN->next = req->next;
                    req->next = NN;
                    req = NN;
                    temp->next = res->next;
                    res = res->next;
                }
                else{
                    temp = temp->next;
                    res = res->next;
                }
            }
        }
        else{
            ListNode* temp = NULL;
            req = res;
            ListNode* p = res;
            res =res->next;
            while(res){
                if(res->val < x){
                    if(temp==NULL){
                        ListNode* NN = new ListNode(res->val);
                        NN->next = head;
                        head = NN;
                        temp = NN;
                        p->next = res->next;
                        res = res->next;
                    }
                    else{
                        ListNode* NN = new ListNode(res->val);
                        temp->next = NN;
                        NN->next = req;
                        temp = NN;
                        p->next = res->next;
                        res = res->next;
                        }
                    }
                else{
                    p=p->next;
                    res = res->next;
                }
                }
            }
        return head;
    }
};