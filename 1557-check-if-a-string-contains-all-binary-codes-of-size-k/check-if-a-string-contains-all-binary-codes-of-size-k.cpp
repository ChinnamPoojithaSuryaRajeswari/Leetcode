class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int>mpp;
        int i=0,j=0,val = pow(2,k+1)-1,ones=0,res=0;
        for(int i = 0; i + k <= s.size(); i++) {
            mpp[s.substr(i, k)]++;
        }
        int total = (1<<k);
        for(int i = 0; i < total; i++) {
            int num = i;
            string pooji = "";
            for(int j = 0; j < k; j++) {
                if(num & 1)
                    pooji += '1';
                else
                    pooji += '0';
                num >>= 1;
            }
            reverse(pooji.begin(), pooji.end());
            if(mpp.find(pooji) == mpp.end())
                return false;
        }
        return true;
    }
};