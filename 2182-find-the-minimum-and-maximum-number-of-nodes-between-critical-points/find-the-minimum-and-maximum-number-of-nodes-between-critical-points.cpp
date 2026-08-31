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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL) return {-1,-1};
        if(head->next == NULL) return {-1,-1};
        if(head->next->next == NULL) return {-1,-1};
        ListNode* temp = head;
        vector<int>vec;
        vector<int> ans;
        int pre = temp->val;
        temp = temp->next;
        int len=0;
        while(temp->next){
            len+=1;
            if(temp->val > pre and temp->val > temp->next->val){
                vec.push_back(len);
            }
            if(temp->val < pre and temp->val < temp->next->val){
                  vec.push_back(len);
            }
            pre = temp->val;
            temp=temp->next;
        }
        if(vec.size()<2) return {-1,-1};
        int mini = vec[1]-vec[0],maxi = vec[vec.size()-1]-vec[0];
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i+1]-vec[i] < mini ){
                mini = vec[i+1]-vec[i];
            }
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};