class Solution {
public:
    int getLucky(string s, int k) {
        long long res = 0;
        for(int i=0;i<s.size();i++){
            int p = int(s[i])-int('a');
            p+=1;
            while(p){
                res = res + (p%10);
                p=p/10;
            }
        }
        k-=1;
        long long req=res;
        while(k){
            res= req;
            req = 0;
            while(res){
                req = req + (res%10);
                res = res/10;
            }
            k-=1;
            cout<<req<<endl;
        }
        return req;
    }
};