class Solution {
public:
    int maxDepth(string s) {
        int open = 0,maxxyAns = 0;
        for(auto it:s){
            if(it=='('){
                open += 1;
                maxxyAns = max(maxxyAns,open);
            }
            if(it==')')open-=1;
        }
        return maxxyAns;
    }
};