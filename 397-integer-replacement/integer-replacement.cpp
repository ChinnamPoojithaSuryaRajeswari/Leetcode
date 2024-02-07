class Solution {
public:
    void requrmnt(long long n,vector<int>&v,int c){
        if(n==1){
            v.push_back(c);
            return;
        }
        else if(n<1){
            return ;
        }
        if(n%2==0){
            requrmnt(n/2,v,c+1);
        }
        else{
            requrmnt(n+1,v,c+1);
            requrmnt(n-1,v,c+1);
        }
    }
    int integerReplacement(int n) {
        vector<int>v;
        long long num = n;
        requrmnt(num,v,0);
        return *min_element(v.begin(),v.end());
    }
};