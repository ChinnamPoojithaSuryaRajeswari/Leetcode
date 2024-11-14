class Solution {
public:
     bool solve(int n, vector<int>& quantities, int item)
    {
        if(item == 0) return false;
        int ss = 0;
        for(int i=0;i<quantities.size();i++)
        {
            ss += quantities[i]%item!=0 ? quantities[i]/item+(1):quantities[i]/item;
            if(ss > n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
         int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(solve(n, quantities, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};