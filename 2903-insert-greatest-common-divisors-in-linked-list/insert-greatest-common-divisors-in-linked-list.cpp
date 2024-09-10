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
    int gcd(int a,int b){
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp = head;
        ListNode* res = head;
        while(res){
            temp = res->next;
            if(temp){
                ListNode* NN = new ListNode(gcd(temp->val,res->val));
                res->next = NN;
                NN->next = temp;
            }
            else{
                return head;
            }
            res = temp;
        }
        return head;
    }
};