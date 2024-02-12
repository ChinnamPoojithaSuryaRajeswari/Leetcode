class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int i = 0,j = 0;
        while(i<word1.size() and j<word2.size()){
            s+=word1[i];
            s+=word2[j];
            i+=1;
            j+=1;
        }
        while(j<word2.size()){
            s+=word2[j];
            j+=1;
        }
        while(i<word1.size()){
            s+=word1[i];
            i+=1;
        }
        return s;
    }
};