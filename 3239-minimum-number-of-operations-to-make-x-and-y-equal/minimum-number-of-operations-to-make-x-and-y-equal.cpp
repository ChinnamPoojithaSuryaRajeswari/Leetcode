class Solution {
public:
    void solve(int x,int &y,int cnt,int& mini,map<int, int>& memo){
        if(cnt > mini)return;
        if(x==y){
            mini = min(mini,cnt);
            return;
        }
        if(memo[x] <= cnt and memo[x]!=0)return;
        memo[x]=cnt;
        if(x%11==0){
            solve(x/11,y,cnt+1,mini,memo);
        }
        if(x%5==0){
            solve(x/5,y,cnt+1,mini,memo);
        }
        solve(x+1,y,cnt+1,mini,memo);
        if(x>0)solve(x-1,y,cnt+1,mini,memo);
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        int mini = INT_MAX;
        map<int, int> memo;
        solve(x,y,0,mini,memo);
        return mini;
    }
};