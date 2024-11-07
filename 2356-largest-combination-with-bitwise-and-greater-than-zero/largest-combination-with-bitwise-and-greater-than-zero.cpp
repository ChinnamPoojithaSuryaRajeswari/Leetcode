class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>vec(24,0);
        int maxi=INT_MIN;
        for(int i=0;i<candidates.size();i++){
            int k = candidates[i],j=0;
            while(k){
                if(k&1==1){
                    vec[j] = vec[j]+1;
                    maxi = max(maxi,vec[j]);
                    
                }
                k=k>>1;
                j+=1;
            }
        }
        return maxi;
    }
};