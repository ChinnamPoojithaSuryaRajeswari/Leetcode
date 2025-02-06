class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = INT_MIN,prev = 0;
        sort(citations.begin(),citations.end());
        for(int i=0;i<citations.size();i++){
            for(int j=prev;j<=citations[i];j++){
                if(j<=citations.size()-i)ans = max(ans,j);
            }
            prev = citations[i];
        }
        return ans;
    }
};