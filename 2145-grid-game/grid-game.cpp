class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans=9223372036854775807,s=0,p=0;
        vector<vector<long long>>prefix(2,vector<long long>(grid[0].size(),0));
        grid[0][0]=0;
        grid[1][grid[0].size()-1]=0;
        for(int i=0;i<grid[0].size();i++){
            s+=grid[0][i];
            p+=grid[1][i];
            prefix[0][i]=s;
            prefix[1][i]=p;
        }
        for(int i=0;i<grid[0].size();i++){
            long long val=0;
            if(i-1>=0){
                val = prefix[1][i-1];
            }
            ans = min(ans, max(prefix[0][prefix[0].size()- 1] - prefix[0][i],val));
        }
        return ans;
    }
};