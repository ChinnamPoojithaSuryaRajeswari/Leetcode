class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int p = 0,ans = 0,n=0;
        for(int i = 0 ; i < gas.size() ; i++){
            if(gas[i] < cost[i]){
                if(p-(cost[i]-gas[i])<0){
                    n += (p-(cost[i]-gas[i]));
                    p=0;
                }
                else{
                    p-=(cost[i]-gas[i]);
                }
            }
            else{
                if(p==0){
                    ans = i;
                }
                p += (gas[i]-cost[i]);
            }
        }
        // cout<<n<<" "<<p<<endl;
        if((-1)*n>p)return -1;
        return ans;
    }
};