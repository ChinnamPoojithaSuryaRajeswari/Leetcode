class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mpp;
        for(auto it:t)mpp[it]++;
        int i=0,j=0;
        string ans="";
        while(j<s.size()){
            mpp[s[j]]--;
            while(i<=j and mpp[s[i]]<0){
                mpp[s[i]]++;
                i++;
            }
            bool flag = true;
            for(auto it:mpp){
                if(it.second > 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(ans=="" || ans.size() > j-i+1){
                    ans = s.substr(i,j-i+1);
                }
            }
            j++;
        }
        return ans;
    }
};