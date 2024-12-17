class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>>pq;
        map<char,int>mpp;
        string ans="";
        for(int i=0;i<s.size();i++){
            mpp[s[i]]+=1;
        }
        for(auto it:mpp){
            pq.push({it.first,it.second});
        }
        while(1 and !pq.empty()){
            char p = pq.top().first;
            int m = pq.top().second;
            if(m<=repeatLimit){
                for(int i=0;i<m;i++){
                    ans+=p;
                }
                pq.pop();
            }
            else{
                pq.pop();
                for(int i=0;i<repeatLimit;i++){
                    ans+=p;
                }
                if(!pq.empty()){
                    char pm = pq.top().first;
                    int mp = pq.top().second;
                    m=m-repeatLimit;
                    mp-=1;
                    ans+=pm;
                    pq.pop();
                    pq.push({p,m});
                    if(mp>0){
                        pq.push({pm,mp});
                    }
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};