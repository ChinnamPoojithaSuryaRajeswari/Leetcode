class Solution {
public:
    pair<int,int> solve(int i,int j,string &s){
        while(i>=0 and j<s.size()){
            if(s[i]!=s[j])break;
            i-=1;
            j+=1;
        }
        // cout<<i<<" "<<j<<endl;
        return {i+1,j-1};
    }
    string longestPalindrome(string s) {
        int ans = 0,left=0,right=0;
        for(int i=0;i<s.size();i++){
            pair<int,int> odd = solve(i,i,s);
            pair<int,int> even = solve(i,i+1,s);
            // cout<<odd.first<<" "<<odd.second<<" "<<even.first<<" "<<even.second<<endl;
            if(ans < odd.second-odd.first+1){
                ans = odd.second-odd.first+1;
                left = odd.first;
                right = odd.second;
            }
            if(ans < even.second-even.first+1){
                ans = even.second-even.first+1;
                left = even.first;
                right = even.second;
            }
        }
        return s.substr(left,right-left+1);
    }
};