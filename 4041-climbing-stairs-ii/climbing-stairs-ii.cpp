class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>vec(costs.size()+1,INT_MAX);
        for(int i=0;i<costs.size();i++){
            if(i-1>=0){
                vec[i] = min(vec[i-1]+costs[i]+1,vec[i]);
            }
            else{
                vec[i] = min(costs[i]+1,vec[i]);
            }
            if(i-2>=0){
                vec[i] = min(vec[i-2]+costs[i]+4,vec[i]);
            }
            else{
                vec[i] = min(costs[i]+4,vec[i]);
            }
            if(i-3>=0){
                vec[i] = min(vec[i-3]+costs[i]+9,vec[i]);
            }
            else{
                vec[i] = min(costs[i]+9,vec[i]);
            }
        }
        return vec[n-1];
    }
};