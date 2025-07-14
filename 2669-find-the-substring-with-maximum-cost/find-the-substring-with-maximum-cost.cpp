class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int ans=0,maxxy=0;
        map<char,int>mpp;
        for(int i=0;i<chars.size();i++){
            mpp[chars[i]]=vals[i];
        }
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()){
                ans+=mpp[s[i]];
            }
            else{
                ans+=(int(s[i])-int('a')+1);
            }
            maxxy = max(maxxy,ans);
            if(ans<0){
                ans=0;
            }
        }
        return maxxy;
    }
};