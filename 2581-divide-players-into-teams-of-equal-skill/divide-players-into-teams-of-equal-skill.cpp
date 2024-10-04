class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        long long s = 0;
        sort(skills.begin(),skills.end());
        int i=0,j=skills.size()-1;
        int ref = skills[i]+skills[j];
        while(i<j){
            if(skills[i]+skills[j]!=ref){
                return -1;
            }
            s+=(skills[i]*skills[j]);
            i+=1;
            j-=1;
        }
        return s;
    }
};