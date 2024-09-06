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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int>mpp;
        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]]=1;
        }
        ListNode* temp = head;
        ListNode* res = head;
        while(temp){
            if(mpp[temp->val]){
                if(temp==head){
                    temp = temp->next;
                    head = temp;
                    res = head;
                }
                else{
                    res->next =  temp->next;
                    temp = res->next;
                }
            }
            else{
                res = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};