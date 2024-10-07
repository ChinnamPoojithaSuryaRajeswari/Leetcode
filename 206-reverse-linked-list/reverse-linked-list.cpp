/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
 */
class Solution {
public:
    ListNode* rec(ListNode* root){
        if(root==NULL) return NULL;
        if(root->next==NULL) return root;
        ListNode* finl = rec(root->next);
        rec(root->next)->next = root;
        root->next = NULL;
        return finl;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* root=head;
        return rec(head);
        // return root;
    }
};