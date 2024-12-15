class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>>pq;
        double ans=0,k,m;
        for(int i=0;i<classes.size();i++){
            k=(double)classes[i][0]/(double)classes[i][1];
            m=(double)(classes[i][0]+1)/(double)(classes[i][1]+1);
            pq.push({m-k,i});
        }
        while(extraStudents>0){
            int p = pq.top().second;
            classes[p][0]+=1;
            classes[p][1]+=1;
            k=(double)classes[p][0]/(double)classes[p][1];
            m=(double)(classes[p][0]+1)/(double)(classes[p][1]+1);
            pq.pop();
            pq.push({m-k,p});
            extraStudents-=1;
        }
        for(int i=0;i<classes.size();i++){
            ans+=(double)classes[i][0]/(double)classes[i][1];
        }
        return (double)ans/(double)classes.size();
    }
};