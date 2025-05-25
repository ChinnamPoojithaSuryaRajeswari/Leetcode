class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mpp;
        int ans=0,odd=0;
        for(auto it:words){
            mpp[it]++;
        }
        for(auto it:mpp){
            string res = it.first;
            int cnt = it.second;
            if(res[0]==res[1]){
                if(cnt%2){
                    odd=1;
                }
                ans += cnt-(cnt%2);
            }
            else{
                string req = "";
                req = res;
                reverse(req.begin(),req.end());
                if(mpp[req]!=0 and mpp[res]!=0){
                cout<<res<<" "<<req<<endl;
                    ans += 2*min(cnt,mpp[req]);
                }
                it.second = 0;
                mpp[req]=0;
            }
        }
        return 2*(ans+odd);
    }
};