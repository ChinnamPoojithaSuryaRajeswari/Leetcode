class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>vec;
        for(int i=0;i<startTime.size();i++){
            if(i==0){
                vec.push_back(startTime[i]);
            }
            else{
                vec.push_back(startTime[i]-endTime[i-1]);
            }
            if(i==startTime.size()-1){
                vec.push_back(eventTime-endTime[i]);
            }
        }
        int s=0,ans=0;
        if(vec.size()<=k+1){
            for(int i=0;i<vec.size();i++){
                ans+=vec[i];
            }
            return ans;
        }
        for(int i=0;i<=k;i++){
            s+=vec[i];
            // cout<<vec[i]<<" ";
        }
        for(int i=k+1;i<vec.size();i++){
            ans=max(ans,s);
            s-=vec[i-k-1];
            s+=vec[i];
            // cout<<vec[i]<<" ";
        }
        ans=max(ans,s);
        return ans; 
    }
};