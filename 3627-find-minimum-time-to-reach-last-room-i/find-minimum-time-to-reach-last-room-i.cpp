class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        vector<vector<long long>>dist(n,vector<long long>(m,LONG_MAX));
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
        long long x=0;
        pq.push({x,0,0});
        while(!pq.empty()){
            vector<long long>vec=pq.top();
            pq.pop();
            long long cost=vec[0],i=vec[1],j=vec[2],c;
            if(i-1>=0){
                x=moveTime[i-1][j]+1;
                c=max(cost+1,x);
                if(c<dist[i-1][j]){
                    dist[i-1][j]=c;
                    pq.push({c,i-1,j});
                }
            }
            if(j-1>=0){
                x=moveTime[i][j-1]+1;
                c=max(cost+1,x);
                if(c<dist[i][j-1]){
                    dist[i][j-1]=c;
                    pq.push({c,i,j-1});
                }
            }
            if(j+1<m){
                x=moveTime[i][j+1]+1;
                c=max(cost+1,x);
                if(c<dist[i][j+1]){
                    dist[i][j+1]=c;
                    pq.push({c,i,j+1});
                }
            }
            if(i+1<n){
                x=moveTime[i+1][j]+1;
                c=max(cost+1,x);
                if(c<dist[i+1][j]){
                    dist[i+1][j]=c;
                    pq.push({c,i+1,j});
                }
            }
        }
        return dist[n-1][m-1];
    }
};