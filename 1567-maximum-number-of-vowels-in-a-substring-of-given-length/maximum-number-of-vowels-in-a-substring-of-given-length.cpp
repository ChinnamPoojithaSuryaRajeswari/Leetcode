class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,maxi=0,ans=0;
        while(i<k){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                ans++;
            }
            i++;
        }
        maxi = max(maxi,ans);
        while(i<s.size()){
            if(s[i-k]=='a' or s[i-k]=='e' or s[i-k]=='i' or s[i-k]=='o' or s[i-k]=='u'){
                ans--;
            }
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                ans++;
            }
            i++;
            maxi = max(maxi,ans);
            cout<<maxi<<" ";
        }
        return maxi;
    }
};