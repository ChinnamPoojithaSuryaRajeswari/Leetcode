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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> anss;
        ListNode* temp = head;
        ListNode* res = head;
        int c = 0;
        ListNode* ans = head;
        while(temp){
            c+=1;
            temp = temp->next;
        }
        temp = head;
        int cnt = c/k;
        int r = c%k;
        if(r) cnt+=1;
        r-=1;
        while(temp){
            if(cnt==0){
                anss.push_back(ans);
                res->next = NULL;
                ans = temp;
                if(r>0){
                    cnt = c/k;
                    cnt+=1;
                    r-=1;
                }
                else{
                    cnt = c/k;
                }
            }
            res = temp;
            temp = temp->next;
            cnt-=1;
        }
        anss.push_back(ans);
        while(anss.size() < k){
            anss.push_back(NULL);
        }
        return anss;
    }
};