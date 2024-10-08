class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>vec;
        for(int i = 1 ; i <= n ; i++){
            vec.push_back(to_string(i));
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(int i = 1 ; i <= n ; i++){
            ans.push_back(stoi(vec[i-1]));
        }
        return ans;
    }
};