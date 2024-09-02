class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s=0;
        vector<long long>prefix;
        for(int i=0;i<chalk.size();i++){
            s+=chalk[i];
            prefix.push_back(s);
        }
        k = k%s;
        if(k==0) return 0;
        int i=0;
        while(k>=prefix[i]){
            i+=1;
        }
        return i;
    }
};