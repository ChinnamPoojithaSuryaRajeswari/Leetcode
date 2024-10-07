class Solution {
public:
    void fun(int i,int n,string s,int& t,int cnt,int c){
        int k=(1e9+7);
        // cout<<cnt;
        if(i>=n){
            return;
        }
        else if(cnt>10 and s[i]>='0' && s[i]<='9'){
            if(c==0 && t>2147483647){
                t=2147483647;
                return;
            }
            else if(c==1 && t>=2147483648){
                t=-2147483648;
                return;
            }
            fun(i+1,n,s,t,cnt,c);
        }
        else if(s[i]=='0' && t==0){
            fun(i+1,n,s,t,cnt,c);
        }
        else if(s[i]>='0' && s[i]<='9'){
            if(cnt<9){
                t=t%k;
                t=(t*10)%k;
                t+=s[i]-'0';
                t=t%k;
                fun(i+1,n,s,t,cnt+1,c);
            }
            else{
                long long y=t;
                y*=10;
                y+=(s[i]-'0');
                if(c==0 && y>2147483647){
                    t=2147483647;
                    return;
                }
                else if(c==1 && y>=2147483648){
                    t=-2147483648;
                    return;
                }
                else{
                    t=y;
                    fun(i+1,n,s,t,cnt+1,c);
                }
            }
        }
    }
    int myAtoi(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        else{
            int i=0,res=0,t=0,cnt=0;
            while(i<n && s[i]==' '){
                i+=1;
            }
            if(i<n){
                int ans = 0;
                if(s[i]!='+' && s[i]!='-'){
                    fun(i,n,s,t,cnt,0);
                    return t;
                }
                else{
                    if(s[i]=='-'){
                        fun(i+1,n,s,t,cnt,1);
                        if(t!= -2147483648){
                            t*=-1;
                        }
                    }
                    else{
                        fun(i+1,n,s,t,cnt,0);
                    }
                    return t;
                }
            }
            else{
                return 0;
            }
        }
        return 0;
    }
};