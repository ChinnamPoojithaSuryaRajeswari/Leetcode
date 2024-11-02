class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,ans=0;
        while(i<g.size() and j<s.size()){
            if(g[i]<=s[j]){
                j+=1;
                i+=1;
                ans+=1;
            }
            else if(g[i]>s[j]){
                j+=1;
            }
            // else{
            //     i+=1;
            // }
        }
        return ans;
    }
};