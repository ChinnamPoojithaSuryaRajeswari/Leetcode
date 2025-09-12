class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& sender) {
        map<string,int>mpp;
        for(int i=0;i<messages.size();i++){
            int ans=0;
            for(int j=0;j<messages[i].size();j++){
                if(messages[i][j]==' ')ans++;
            }
            mpp[sender[i]]+=ans;
            mpp[sender[i]]++;
        }
        int maxi=0;
        string answery = "";
        for(auto it:mpp){
            if(it.second >= maxi){
                maxi = it.second;
                answery = max(it.first,answery);
            }
        }
        return answery;
    }
};