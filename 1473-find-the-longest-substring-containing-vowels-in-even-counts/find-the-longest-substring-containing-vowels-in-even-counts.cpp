class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char,int>mpp;
        vector<int> vec;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                vec.push_back(int(s[i]));
            }
            else if(s[i]=='e'){
                vec.push_back(int(s[i]));
            }
            else if(s[i]=='i'){
                vec.push_back(int(s[i]));
            }
            else if(s[i]=='o'){
                vec.push_back(int(s[i]));
            }
            else if(s[i]=='u'){
                vec.push_back(int(s[i]));
            }
            else{
                vec.push_back(0);
            }
        }
        int S=0;
        for(int i=0;i<vec.size();i++){
            S = S^vec[i];
            vec[i] = S;
        }
        int ans=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]==0){
                ans = max(ans,i+1);
            }
            else{
                if(mpp[vec[i]]!=0){
                    ans = max(ans,i-mpp[vec[i]]+1);
                }
                else{
                    mpp[vec[i]]=i+1;
                }
            }
        }
        return ans;
    }
};