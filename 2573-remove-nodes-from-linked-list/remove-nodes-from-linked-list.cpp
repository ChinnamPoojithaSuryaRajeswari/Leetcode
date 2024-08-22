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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* nh=NULL;
        while(temp){
            ListNode* NN = new ListNode(temp->val);
            if(nh==NULL){
                nh = NN;
            }
            else{
                NN->next = nh;
                nh = NN;
            }
            temp = temp->next;
        }
        stack<int>st;
        temp = nh;
        ListNode* prev;
        ListNode* cur;
        while(temp){
            if(st.empty()){
                 ListNode* NN = new ListNode(temp->val);
                st.push(temp->val);
                cur = NN;
                nh = cur;
            }
            else{
                if(st.top() <= temp->val){
                    ListNode* NN = new ListNode(temp->val);
                    st.push(temp->val);
                    NN->next = cur;
                    cur = NN;
                }
            }
            temp = temp->next;
        }
        return cur;
    }
};