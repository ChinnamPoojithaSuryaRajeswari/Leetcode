class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        int i=0,j=pizzas.size()-1,flag=1;
        int res;
        res = (pizzas.size()/4);
        if(res%2==1){
            res = res/2;
            res+=1;
        }
        else res = res/2;
        long long ans = 0;
        // cout<<res<<" ";
        int val = pizzas.size()/8;
        while(res){
            ans+=pizzas[j];
            j--;
            res--;
        }
        // cout<<val<<" ";
        while(val){
            val--;
            j--;
            ans+=pizzas[j];
            j--;
        }
        return ans;
    }
};