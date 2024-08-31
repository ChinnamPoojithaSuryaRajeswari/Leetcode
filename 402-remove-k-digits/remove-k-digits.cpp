class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() < k) return "0";
        stack<char>st;
        int i=0;
        while(k and i<num.size()){
            if(st.empty()){
                st.push(num[i]);
            }
            else{
                while(!st.empty() and st.top()>num[i]){
                    k-=1;
                    st.pop();
                    if(k==0){
                        break;
                    }
                }
                st.push(num[i]);
            }
            i+=1;
        }
        while(k > 0 and !st.empty()){
            st.pop();
            k-=1;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(i<num.size()){
            ans+=num[i];
            i+=1;
        }
        i=0;
        while(i<ans.size()){
            if(ans[i]=='0'){
                ans.erase(ans.begin()+i);
            }
            else{
                break;
            }
        }
        if(ans.size()==0) return "0";
        return ans;
    }
};