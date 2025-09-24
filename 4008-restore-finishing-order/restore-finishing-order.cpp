class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        map<int,int>mpp;
        for(int i=0;i<friends.size();i++)mpp[friends[i]]+=1;
        for(int i=0;i<order.size();i++)if(mpp[order[i]])ans.push_back(order[i]);
        return ans;
    }
};