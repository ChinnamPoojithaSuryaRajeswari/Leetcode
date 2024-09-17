class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mpp;
        string s="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                mpp[s]+=1;
                s="";
            }
            else{
                s+=s1[i];
            }
        }
        mpp[s]+=1;
        s="";
        vector<string>vec;
        for(int j=0;j<s2.size();j++){
            if(s2[j]==' '){
                mpp[s]+=1;
                s="";
            }
            else{
                s+=s2[j];
            }
        }
        mpp[s]+=1;
        for(auto it:mpp){
            if(it.second==1){
                vec.push_back(it.first);
            }
        }
        return vec;
    }
};