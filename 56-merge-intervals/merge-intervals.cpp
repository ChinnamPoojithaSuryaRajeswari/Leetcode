class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>answer;
        int l = intervals[0][0];
        int r = intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0] > r){
                answer.push_back({l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else{
                r = max(r,intervals[i][1]);
                l = min(l,intervals[i][0]);
            }
        }
        answer.push_back({l,r});
        return answer;
    }
};