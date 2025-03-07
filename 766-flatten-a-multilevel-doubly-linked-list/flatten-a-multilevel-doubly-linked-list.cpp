/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void solve(Node* &ans,Node* head,Node* &temp){
        if(head==NULL){
            return;
        }
        while(head){
            if(head->child!=NULL){
                cout<<head->child->val<<" ";
                if(ans==NULL){
                    Node* NN = new Node(head->val);
                    ans = NN;
                    temp = ans;
                }
                else{
                    Node* NN = new Node(head->val);
                    ans->next = NN;
                    NN->prev = ans;
                    ans = NN;
                }
                solve(ans,head->child,temp);
            }
            else if(ans==NULL){
                Node* NN = new Node(head->val);
                ans = NN;
                temp = ans;
            }
            else{
                Node* NN = new Node(head->val);
                ans->next = NN;
                NN->prev = ans;
                ans = NN;
            }
            head = head->next;
        }
    }
    Node* flatten(Node* head) {
        Node* ans = NULL;
        Node* temp = NULL;
        solve(ans,head,temp);
        return temp;
    }
};