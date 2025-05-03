class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
         int ans=INT_MAX;
        for(int i = 1 ; i < 7 ; i++){
            int c=0;
            for(int j = 0 ; j < tops.size();j++){
                if(tops[j]!=i){
                    if(bottoms[j]!=i){
                        c=-1;
                        break;
                    }
                    else{
                        c+=1;
                    }
                }
            }
            if(c!=-1){
                ans=min(c,ans);
            }
            c=0;
            for(int j = 0 ; j < tops.size();j++){
                if(bottoms[j]!=i){
                    if(tops[j]!=i){
                        c=-1;
                        break;
                    }
                    else{
                        c+=1;
                    }
                }
            }
            if(c!=-1){
                ans=min(c,ans);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};