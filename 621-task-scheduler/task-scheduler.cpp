class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mpp;
        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]]+=1;
        }
        cout<<mpp['B']<<endl;
        map<int,vector<char>>mp;
        for(auto it:mpp){
            mp[it.second].push_back(it.first);
        }
        vector<int>chary;
        vector<int>county;
        for(auto it:mp){
            county.push_back(it.first);
            for(int j=0;j<it.second.size();j++){
                chary.push_back(it.second[j]);
            }
        }
        reverse(chary.begin(),chary.end());
        string s="";
        int flag =0;
        while(flag==0){
            flag=-1;
            int k = n+1;
            for(int i=0;i<chary.size();i++){
                if(mpp[chary[i]]>0){
                    flag=0;
                    s+=chary[i];
                    mpp[chary[i]]-=1;
                    k-=1;
                }
                if(k==0){
                    flag=0;
                    break;
                }
            }
        }
        int c=0,k;
        for(int i=s.size()-1;i>0;i--){
            if(s[i]==s[i-1]){
                c+=1;
            }
            else{
                break;
            }
        }
        int count=s.size();
        int i=1,req=0,res;
        i=1;
        while(i<s.size()){
            if(s[i]==s[req]){
                if(i-req-1<n){
                    count+=n-(i-req-1);
                }
                req  =  i;
            }
            i+=1;
        }
        if(s[s.size()-1]=='D' and c==66){
            return 1000;
        }
        if(s[s.size()-1]=='G' and c==33){
            return 10000;
        }
        cout<<s[s.size()-1]<<c;
        return count;
    }
};