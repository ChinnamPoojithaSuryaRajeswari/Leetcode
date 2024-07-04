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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = head;
        int s=0;
        ListNode* ans=NULL;
        while(res->next){
            if(res->val==0){
                if(s!=0){
                    ListNode* NN = new ListNode(s);
                    if(ans==NULL){
                        ans= NN;
                        head = ans;
                    }
                    else{
                        ans->next = NN;
                        ans = NN;
                    }
                }
                s=0;
            }
            else{
                s+=res->val;
            }
            res=res->next;
        }
        ListNode* NN = new ListNode(s);
        if(ans==NULL){
            ans= NN;
            head = ans;
        }
        else{
            ans->next = NN;
            ans = NN;
        }
        return head;
    }
};