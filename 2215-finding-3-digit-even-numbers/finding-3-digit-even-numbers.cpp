class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>mpp;
        for(int i=0;i<digits.size();i++){
            mpp[digits[i]]+=1;
        }
        vector<int> ans;
        for(int i=100;i<=999;i+=2){
            unordered_map<int,int>mp;
            mp = mpp;
            int k = i;
            while(k){
                if(mp[k%10]){
                    mp[k%10]--;
                }
                else{
                    break;
                }
                k=k/10;
            }
            if(k==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};