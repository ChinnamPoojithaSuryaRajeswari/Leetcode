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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL){
            return head;
        }
        ListNode* temp = head->next;
        ListNode* res= head;
        ListNode* p=NULL;
        int cnt=0;
        while(temp){
            if(temp->val==res->val){
                cnt+=1;
                res->next = temp->next;
                temp->next = NULL;
                temp = res->next;
            }
            else{
                if(cnt == 0){
                    if(p==NULL){
                        p = res;
                        head = p;
                    }
                    else{
                    p = res;
                    }
                    res = res->next;
                    temp = temp->next;
                }
                else{
                    if(p!=NULL){
                        p->next = temp;
                        res=p;
                        res = res->next;
                        temp = temp->next;
                    }
                    else{
                        res = res->next;
                        temp = temp->next;
                    }
                }
                cnt=0;
            }
        }
        if(cnt == 0){
            if(p==NULL){
                p = res;
                head = p;
            }
            else{
            p = res;
            }
        }
        else{
            if(p!=NULL){
                p->next = temp;
                res=p;
            }
        }
        if(p==NULL) return NULL;
        return head;
    }
};