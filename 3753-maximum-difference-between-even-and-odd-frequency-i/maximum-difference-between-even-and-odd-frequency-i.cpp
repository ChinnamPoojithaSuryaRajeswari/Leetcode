class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int even = INT_MAX,odd = INT_MIN;
        for(auto it:mpp){
            if(it.second%2==0)even = min(even,it.second);
            if(it.second%2==1)odd = max(odd,it.second);
        }
        if(even==INT_MAX)even = 0;
        if(odd==INT_MIN)odd = 0;
        return odd-even;
    }
};