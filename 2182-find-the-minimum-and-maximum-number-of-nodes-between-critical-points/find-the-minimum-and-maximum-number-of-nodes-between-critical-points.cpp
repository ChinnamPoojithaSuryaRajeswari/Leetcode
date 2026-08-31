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
        ListNode* prev=head;
        ListNode* current=head->next;
        int mnnnii=INT_MAX;
        int len = 1;
        int maxDist=-1,minDist=-1,mini=INT_MAX,maxi=-1;
        while(current){
            len+=1;
            if(current->next){
                if(current->val > current->next->val and current->val > prev->val){
                    minDist = max(minDist,maxDist);
                    mnnnii = min(mnnnii,len);
                    maxDist = len;
                }
                if(current->val < current->next->val and current->val < prev->val){
                    minDist = max(minDist,maxDist);
                    mnnnii = min(mnnnii,len);
                    maxDist = len;
                }
                if(maxDist!=-1 and minDist!=-1 and maxDist!=minDist){
                cout<<minDist<<" "<<maxDist<<endl;
                    mini = min(mini,abs(minDist-maxDist));
                }
            }
            else{
                break;
            }
            prev = current;
            current = current->next;
        }
        if(maxDist!=0 and mnnnii!=INT_MAX and maxDist!=mnnnii){
            maxi = maxDist - mnnnii;
        }
        return {mini==INT_MAX ? -1:mini,maxi};
    }
};