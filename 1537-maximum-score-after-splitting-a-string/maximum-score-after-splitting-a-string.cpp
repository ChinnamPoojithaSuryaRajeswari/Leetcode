class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        vector<int>zero;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')ans++;
            zero.push_back(ans);
        }
        ans=0;
        int maxi = INT_MIN;
        for(int i=s.size()-1;i>0;i--){
            if(s[i]=='1')ans++;
            maxi = max(maxi,ans+zero[i-1]);
        }
        return maxi;
    }
};