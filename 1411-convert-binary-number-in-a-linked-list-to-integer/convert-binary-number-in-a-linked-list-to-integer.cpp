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
    int getDecimalValue(ListNode* head) {
        vector<int>v;
        int s=0;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        int c=0;
        for(int i=v.size()-1;i>=0;i--){
            s+=v[i]*(int)pow(2,c);
            c+=1;
        }
        return s;
    }
};