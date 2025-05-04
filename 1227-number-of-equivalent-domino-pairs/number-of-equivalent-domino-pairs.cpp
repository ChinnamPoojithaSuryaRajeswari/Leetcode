class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int>mpp;
        int cnt=0;
        for(int i = 0 ;i < dominoes.size();i++){
            sort(dominoes[i].begin(),dominoes[i].end());
            if(mpp[dominoes[i]]!=0){
                cnt+=mpp[dominoes[i]];
            }
            mpp[dominoes[i]]++;
        }
        return cnt;
    }
};