class Solution {
public:
    unordered_map<string,int>mpp;
    int solve(vector<vector<string>> &vec,int indx,string prev){
        if(indx>=vec.size())return 0;
        int maxi = 0;
        if(mpp[prev]!=0)return mpp[prev];
        for(int i=0;i<vec[indx].size();i++){
            if(prev==" "){
                maxi = max(maxi,(1+solve(vec,indx+1,vec[indx][i])));
            }
            else{
                int cnt=0;
                for(int j=0;j<prev.size()+1;j++){
                    if(prev[j-cnt]!=vec[indx][i][j]){
                        cnt++;
                    }
                }
                if(cnt==1){
                    maxi = max(maxi,(1+solve(vec,indx+1,vec[indx][i])));
                }
            }
        }
        if(prev!=" ")mpp[prev] = maxi;
        return maxi;
    }
    int longestStrChain(vector<string>& words) {
        vector<vector<string>>vec(17);
        vector<string>res;
        int minlen = INT_MAX;
        for(int i=0;i<words.size();i++){
            vec[words[i].size()].push_back(words[i]);
            int req = words[i].size();
            minlen = min(minlen,req);
        }
        int ans = INT_MIN;
        for(int i=1;i<17;i++){
            ans = max(ans,solve(vec,i," "));
        }
        return ans;
    }
};