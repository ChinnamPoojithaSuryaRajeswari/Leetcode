class Solution {
public: 
    long long fun(long long n,unordered_map<long long,int>&memo){
        if(n==1){
            return 0;
        }
        if(memo[n]!=0){
            return memo[n];
        }
        int x=1;
        if(n%2){
            x+=min(fun(n-1,memo),fun(n+1,memo));
        }
        else{
            x+=fun(n/2,memo);
        }
        return memo[n]=x;
    }
    int integerReplacement(int n) {
        unordered_map<long long,int>memo;
        return fun(n,memo);
    }
};