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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp = head;
        int k = st.size(),max=0;
        while(k){
            if(max < temp->val+st.top()){
                max = temp->val+st.top();
            }
            st.pop();
            temp=temp->next;
            k-=1;
        }
        return max;
    }
};