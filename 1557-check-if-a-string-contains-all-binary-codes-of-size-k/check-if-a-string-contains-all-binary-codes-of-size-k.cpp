class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int>mpp;
        int i=0,j=0,val = pow(2,k+1)-1,ones=0,res=0;
        for(int i = 0; i + k <= s.size(); i++) {
            mpp[s.substr(i, k)]++;
        }
        for(int i=0;i<=pow(2,k)-1;i++){
            int ressy = i, len=0 ;
            string pooji = "";
            while(ressy){
                if(ressy&1){
                    pooji+='1';
                }
                else{
                    pooji+='0';
                }
                len++;
                ressy = ressy>>1;
            }
            while(len<k){
                pooji+='0';
                len++;
            }
            int l = 0;
            int m = pooji.size() - 1;
            while (l < m) {
                swap(pooji[l], pooji[m]);
                l++;
                m--;
            }
            cout<<pooji<<" ";
            if(mpp[pooji]==0)return false;
        }
        return true;
    }
};