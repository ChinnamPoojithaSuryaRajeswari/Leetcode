class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long sum=0;
        for(int i=0;i<rolls.size();i++){
            sum+=rolls[i];
        }
        long long prod = mean*(n+rolls.size());
        prod = prod - sum;
        vector<int>ans(n,0);
        int i=0;
        if(prod > n*6 or prod<=0){
            return {};
        }
        int flag=0;
        while(prod>0){
            ans[i]+=1;
            i+=1;
            if(i==ans.size()){
                flag=1;
            }
            i=i%ans.size();
            prod-=1;
        }
        if(flag==1){
        return ans;
        }
        return {};
    }
};