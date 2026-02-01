class Solution {
public:
    int minimumCost(vector<int>& arr) {
        int k=arr[0];
        int l= *min_element(arr.begin()+1,arr.end());
        arr.erase(min_element(arr.begin()+1,arr.end()));
        int p= *min_element(arr.begin()+1,arr.end());
        return k+l+p;
    }
};