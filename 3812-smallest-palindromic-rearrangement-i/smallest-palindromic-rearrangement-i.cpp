class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        string front="",back="";
        for(auto it:mpp){
            for(int k=0;k<it.second/2;k++){
                front+=it.first;
                mpp[it.first]--;
            }
            for(int k=0;k<it.second/2;k++){
                back+=it.first;
                mpp[it.first]--;
            }
        }
        for(auto it:mpp){
            if(it.second!=0){
                front+=it.first;
            }
        }
        int i=0,j=back.size()-1;
        while(i<j){
            char temp  =  back[i];
            back[i] = back[j];
            back[j] = temp;
            i++;
            j--;
        }
        front+=back;
        return front;

    }
};