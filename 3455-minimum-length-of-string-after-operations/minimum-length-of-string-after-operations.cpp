class Solution {
public:
    int minimumLength(string s) {
         map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]+=1;
        }
        int l=0;
        for(auto i:m){
            if(i.second<=2){
                l+=i.second;
            }
            else{
                if(i.second%2==0){
                    l+=2;
                }
                else{
                    l+=1;
                }
            }
        }
        return l;
    }
};