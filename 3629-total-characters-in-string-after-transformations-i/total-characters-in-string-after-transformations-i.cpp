class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>prev(26,0);
        int e = 1e9+7,ans=0;
        for(int i = 0 ; i < s.size() ; i++){
            prev[s[i]-'a']+=1;
        }
        for(int i = 0 ; i < t ; i++){
            vector<int>curr(26,0);
            for(int j = 1 ; j < 26 ; j++){
                if(prev[j-1]){
                    curr[j] = (prev[j-1])%e;
                }
            }
            if(prev[25]){
                curr[0] = ((curr[0]%e)+ (prev[25])%e)%e;
                curr[1] = ((curr[1]%e)+ (prev[25])%e)%e;
            }
            prev = curr;
        }
        for(auto it:prev){
            ans = ((ans%e)+(it%e))%e;
        }
        return ans;
    }
};