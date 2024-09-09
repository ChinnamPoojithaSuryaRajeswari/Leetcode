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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> spiral(m,vector<int>(n,-1));
        int east=n-1,west=0,north=1,south=m-1,e=1,w=0,N=0,s=0,i=0,j=0;
        ListNode* temp = head;
        while(temp!=NULL){
            if(e==1){
                while(temp and j<east){
                    spiral[i][j] = temp->val;
                    j+=1;
                    temp = temp->next;
                }
                if(temp){
                    spiral[i][j] = temp->val;
                    temp = temp->next;
                }
                i+=1;
                east = east-1;
                s=1;
                e=0;
            }
            if(s==1){
                while(temp and i<south){
                    spiral[i][j] = temp->val;
                    i+=1;
                    temp = temp->next;
                }
                if(temp){
                    spiral[i][j] = temp->val;
                    temp = temp->next;
                }
                south-=1;
                j-=1;
                s=0;
                w=1;
            }
            if(w==1){
                while(temp and j>west){
                    spiral[i][j] = temp->val;
                    j-=1;;
                    temp = temp->next;
                }
                if(temp){
                    spiral[i][j] = temp->val;
                    temp = temp->next;
                }
                i-=1;
                west = west+1;
                w=0;
                N=1;
            }
            if(N==1){
                while(temp and i>north){
                    spiral[i][j] = temp->val;
                    i-=1;
                    temp = temp->next;
                }
                if(temp){
                    spiral[i][j] = temp->val;
                    temp = temp->next;
                }
                j+=1;
                north = north+1;  
                N=0;
                e=1;
            }
        }
        return spiral;
    }
};