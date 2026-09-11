class Solution {
public:
    int ans=0;
    map<int,int>mpp;
    void solve(vector<int> &digits,int i,int s){
        if(i==3){
            if(s%2==0){
                if(mpp[s]==0)ans++;
                mpp[s]++;
            }
            return;
        }
        for(int j=0;j<digits.size();j++){
            if(i==0 and digits[j]==0){
                continue;
            }
            else{
                if(digits[j]!=-1){
                    int  k  = digits[j];
                    digits[j]=-1;
                    solve(digits,i+1,s*10+k);
                    digits[j]=k;
                }
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        solve(digits,0,0);
        return ans;
    }
};