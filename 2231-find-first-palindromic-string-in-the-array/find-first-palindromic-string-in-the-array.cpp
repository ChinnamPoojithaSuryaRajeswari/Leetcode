class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int j,q,k;
        string p;
        for(int i=0;i<words.size();i++){
            j=0;
            k=words[i].size()-1;
            q=0;
            while(j<k){
                if(words[i][j]!=words[i][k]){
                    q=1;
                    break;
                }
                j+=1;
                k-=1;
            }
            if(q==0){
                p = words[i];
                break;
            }
        }
        return p;
    }
};