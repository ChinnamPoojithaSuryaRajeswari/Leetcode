class Solution {
public:
    int possibleStringCount(string word) {
        int i=0,cnt=0,ans=0;
        while(i<word.size()-1){
            if(word[i]==word[i+1]){
                cnt+=1;
            }
            else{
                ans+=cnt;
                cnt=0;
            }
            i+=1;
        }
        cnt+=ans;
        return cnt+1;
    }
};