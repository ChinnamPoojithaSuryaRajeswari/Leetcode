class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans=0;
        vector<vector<pair<int, int>>> alpha(26, vector<pair<int, int>>());
        for(int i=0;i<original.size();i++){
            alpha[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<int>>pain(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++){
            queue<pair<int,int>>q;
            q.push({i,0});
            pain[i][i]=0;
            while(!q.empty()){
                int cst = q.front().second;
                char current = q.front().first;
                for(int j=0;j<alpha[current].size();j++){
                    if(pain[i][alpha[current][j].first] > cst+alpha[current][j].second){
                        pain[i][alpha[current][j].first] = cst+alpha[current][j].second;
                        q.push({alpha[current][j].first,cst+alpha[current][j].second});
                    }
                }
                q.pop();
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                cout<<pain[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<source.size();i++){
            if(pain[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;
            ans+=pain[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};