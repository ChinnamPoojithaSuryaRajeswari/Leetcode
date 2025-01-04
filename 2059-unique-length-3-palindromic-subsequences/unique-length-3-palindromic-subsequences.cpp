class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>>v;
        vector<vector<int>>vec;
        int n=s.size();
        for(int i=0;i<26;i++){
            vector<int>t(n,0);
            vec.push_back({-1,-1});
            int c=0;
            for(int j=0;j<n;j++){
                int x=s[j];
                x-=97;
                if(x==i){
                    c+=1;
                }
                t[j]=c;
            }
            v.push_back(t);
        }
        for(int i=0;i<n;i++){
            int x=s[i];
            x-=97;
            if(vec[x][0]==-1){
                vec[x][0]=i;
            }
            vec[x][1]=i;
        }
        int res=0;
        for(int i=0;i<26;i++){
            if(v[i][n-1]>=2){
                int l=vec[i][0];
                int r=vec[i][1];
                for(int j=0;j<26;j++){
                    int k=v[j][r]-v[j][l];
                    if(i==j){
                        k-=1;
                    }
                    if(k>0){
                        res+=1;
                    }
                }
            }
        }
        return res;
    }
};