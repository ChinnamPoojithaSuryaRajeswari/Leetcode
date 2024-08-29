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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int>pq;
        ListNode* temp;
        for(int i=0;i<lists.size();i++){
           temp = lists[i];
            while(temp){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* head=NULL;
        while(!pq.empty()){
            ListNode* NN = new ListNode(pq.top());
            if(head==NULL){
                head = NN;
            }
            else{
                NN->next = head;
                head = NN;
            }
            pq.pop();
        }
        return head;
    }
};