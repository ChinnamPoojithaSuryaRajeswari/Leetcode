/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        map<Node*, Node*> mpp;
        
        Node* temp = head;
        while (temp) {
            mpp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        while (temp) {
            mpp[temp]->next = mpp[temp->next];
            mpp[temp]->random = mpp[temp->random];
            temp = temp->next;
        }
        
        return mpp[head];
    }
};