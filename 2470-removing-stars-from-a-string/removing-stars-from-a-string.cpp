class Solution {
public:
    string removeStars(string s) {
        // stack<char> st;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='*' and !st.empty()){
        //         st.pop();
        //     }
        //     else{
        //         st.push(s[i]);
        //     }
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans+=st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        
         
        // int i=0;
        // string ans="";
        // while(i<s.size()-1){
        //     cout<<s<<" "<<i<<endl;
        //     if(s[i+1]=='*'){
        //         s.erase(s.begin()+i);
        //         s.erase(s.begin()+i);
        //         if(i)
        //     }
        //     else{
        //         ans+=s[i];
        //         i+=1;
        //     }
        // }
        // if(s[s.size()-1]!='*'){
        //     ans+=s[s.size()-1];
        // }
        // return ans;
        stack<char>st;
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*'){
                st.push('*');
            }
            if(st.empty()){
                if(s[i]!='*'){
                    ans+=s[i];
                }
            }
            else{
                if(s[i]!='*'){
                    st.pop();
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};