class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<vector<int>>lps;
        for(int i=0;i<words.size();i++){
            vector<int>res;
            int l = 0;
            for(int j=0;j<words[i].size();j++){
                if(words[i][l]==words[i][j] and j!=0){
                    l++;
                    res.push_back(l);
                    // cout<<l<<" ";
                }
                else{
                    l=0;
                    res.push_back(0);
                    // cout<<0<<" ";
                }
            }
            // cout<<endl;
            lps.push_back(res);
        }
        set<string>ans;
        vector<string>r;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i!=j){
                    // cout<<i<<" "<<j<<endl;
                     int p=0;
                    for(int k=0;k<words[j].size();k++){
                        if(words[j][k]==words[i][p]){
                            p++;
                        }
                        else{
                            if(p!=0){
                                p=lps[i][p-1];
                                k--;
                            }
                        }
                        if(p==words[i].size()){
                            // cout<<"asdf";
                            cout<<words[j]<<" "<<words[i]<<endl;
                            ans.insert(words[i]);
                            break;
                        }
                    }
                }
            }
        }
        for(auto it:ans){
            r.push_back(it);
        }
        return r;
    }
};