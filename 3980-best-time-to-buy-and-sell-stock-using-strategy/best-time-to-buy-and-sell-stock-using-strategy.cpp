class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<long long>prefix(prices.size(),0);
        prefix[0] = prices[0]*strategy[0];
        for(int i=1;i<prices.size();i++){
            prefix[i]+=prefix[i-1]+(prices[i]*strategy[i]);
        }
        cout<<prefix[prefix.size()-1]<<" "<<0<<" ";
        long long i=0,val = 0,ans=0;
        while(i<k/2){
            if(strategy[i]==1){
                val -=(prices[i]);
            }
            else if(strategy[i]==-1){
                val += prices[i];
            }
            i++;
        }
        long long j = k/2;
        long long p = k/2;
        while(j<k){
            if(strategy[j]==0){
                val += prices[j];
            }
            else if(strategy[j]==-1){
                val += (2*prices[j]);
            }
            j++;
        }
        i=0;
        cout<<val<<" ";
        long long anssy = prefix[prefix.size()-1],res=0;
        anssy = max(anssy,prefix[prices.size()-1] + val);
        cout<<prefix[prices.size()-1] + val<<" ";
        while(j<prices.size()){
            if(strategy[i]==1){
                val +=(prices[i]);
            }
            else if(strategy[i]==-1){
                val -= prices[i];
            }
            if(strategy[j]==0){
                val += prices[j];
            }
            else if(strategy[j]==-1){
                val += (2*prices[j]);
            }
            if (strategy[p] == 0) val -= prices[p];
            else if (strategy[p] == -1) val -= 2 * prices[p];
            if (strategy[p] == 1) val -= prices[p];
            else if (strategy[p] == -1) val += prices[p];
            cout<<(prefix[prices.size()-1] + val)<<" "<<val<<" ";
            anssy = max(anssy,prefix[prices.size()-1] + val);
            i++;
            p++;
            j++;
        }
        return anssy;
    }
};



// -10 0 8 -2 3 13 8 18 