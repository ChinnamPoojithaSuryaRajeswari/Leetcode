class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=0,nums=1;
        vector<string>ans;
        while(i<target.size()){
            if(target[i]==nums){
                ans.push_back("Push");
                i+=1;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            nums+=1;
        }
        return ans;
    }
};