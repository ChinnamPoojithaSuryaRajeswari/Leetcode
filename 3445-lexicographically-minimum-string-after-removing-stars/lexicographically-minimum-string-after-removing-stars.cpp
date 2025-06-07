class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<int,int>>pq;
        vector<int>res(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!pq.empty()){
                    pq.pop();
                }
            }
            else{
                pq.push({(-1)*(int(s[i])-int('a')),i});
            }
        }
        while(!pq.empty()){
            cout<<pq.top().second<<" ";
            res[pq.top().second]=1;
            pq.pop();
        }
        string ans="";
        for(int i=0;i<res.size();i++){
            if(res[i]==1)ans+=s[i];
        }
        return ans;
    }
};