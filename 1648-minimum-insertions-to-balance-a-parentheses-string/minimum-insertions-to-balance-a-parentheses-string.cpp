class Solution {
public:
    int minInsertions(string s) {
        stack<int>stak;
        int ans=0;
        vector<int>val;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(!stak.empty()){
                    if(stak.top()==1){
                        stak.pop();
                        ans+=1;
                    }
                }
                stak.push(2);
            }
            else{
                if(stak.empty()){
                    val.push_back(i);
                }
                else{
                    if(stak.top()==2){
                        stak.pop();
                        stak.push(1);
                    }
                    else{
                        stak.pop();
                    }
                }
            }
        }
        while(!stak.empty()){
            ans+= stak.top();
            stak.pop();
        }
        int i = 0;
        while (i < val.size()) {
            if (i + 1 < val.size() && val[i] + 1 == val[i + 1]) {
                ans += 1;
                i += 2;
            } else {
                ans += 2;
                i++;
            }
        }
        return ans;
    }
};