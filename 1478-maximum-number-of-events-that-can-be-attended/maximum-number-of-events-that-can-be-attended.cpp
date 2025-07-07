class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        if(events.size()==0){
            return 0;
        }
        int a=events[0][0],answer=0;
        for(int i=0;i<events.size();i++){
            if(a<events[i][0]){
                while(!pq.empty() && a<events[i][0]){
                    if(pq.top()>=a){
                        answer+=1;
                        a+=1;
                    }
                    pq.pop();
                }
                if(a<events[i][0]){
                    a=events[i][0];
                }
                pq.push(events[i][1]);
            }
            else{
                pq.push(events[i][1]);
            }
        }
        while(!pq.empty()){
            if(pq.top()>=a){
                answer+=1;
                a+=1;
            }
            pq.pop();
        }
        return answer;
    }
};