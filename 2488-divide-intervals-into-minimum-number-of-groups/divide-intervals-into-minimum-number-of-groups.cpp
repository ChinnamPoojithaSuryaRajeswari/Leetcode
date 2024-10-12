class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int>pq;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(pq.empty()){
                pq.push((-1)*intervals[i][1]);
            }
            else{
                if((-1)*pq.top() >= intervals[i][0]){
                    pq.push((-1)*intervals[i][1]);
                }
                else{
                    pq.pop();
                    pq.push((-1)*intervals[i][1]);
                }
            }
        }
        return pq.size();
    }
};