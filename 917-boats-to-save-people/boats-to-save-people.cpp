class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = people.size()-1,j=0,cnt=0;
        while(i>=j){
            if(people[i]+people[j]<=limit){
                j++;
                i--;
                cnt++;
            }
            else{
                i--;
                cnt++;
            }
        }
        return cnt;   
    }
};