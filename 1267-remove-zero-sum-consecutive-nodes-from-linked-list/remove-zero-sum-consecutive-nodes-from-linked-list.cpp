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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=head;
        vector<int>vec;
        while(temp){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        temp = head;
        int i=0;
        int j=i;
        while(i<vec.size()){
            j=i;
            int s=0;
            while(j<vec.size()){
                s+=vec[j];
                if(s==0){
                    // cout<<i<<" "<<j<<" ";
                    while(j>=i){
                        vec.erase(vec.begin()+i);
                        j-=1;
                    }
                    i=-1;
                    break;
                }
                j+=1;
            }
            i+=1;
        }
        head=NULL;
        for(int i=0;i<vec.size();i++){
            ListNode* NN = new ListNode(vec[i]);
            if (head==NULL){
                head = NN;
                temp=head;
            }
            else{
            temp->next=NN;
            temp=NN; 
            }
        }
        return head;
    }
};