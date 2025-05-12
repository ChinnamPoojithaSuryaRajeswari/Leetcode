class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>excess;
        for(int i = cardPoints.size()-k ; i < cardPoints.size() ; i++){
            excess.push_back(cardPoints[i]);
        }
        for(int i = 0 ; i < k ; i++){
            excess.push_back(cardPoints[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < k ; i++){
            ans+=excess[i];
        }
        int j = k,a = 0,point = ans;
        while(j<excess.size()){
            point-=excess[a];
            point+=excess[j];
            j++;
            a++;
            ans = max(ans,point);
        }
        return ans;
    }
};