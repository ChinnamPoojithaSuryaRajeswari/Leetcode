class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=*min_element(batteries.begin(), batteries.end()),h=0,ans=0;
        for(int val: batteries)h+=val;
        while (l<=h) {
            long long mid=(l+h)/2;
            long long res=0;
            for (int i=0;i<batteries.size();i++)res+=min((long long)batteries[i], mid);
            if (res>=mid*n) {
                ans=mid;     
                l=mid+1;     
            } 
            else 
                h=mid-1;    
        }
        return ans;
    }
};