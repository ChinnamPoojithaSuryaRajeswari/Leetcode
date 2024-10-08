class Solution {
public:
    int minSwaps(string s) {
        // stack<char>st;
        // for(int i=0;i<s.size();i++){
        //     if(st.empty()){
        //         st.push(s[i]);
        //     }
        //     else{
        //         if(s[i]==']' and st.top()=='['){
        //             st.pop();
        //         }
        //         else{
        //             st.push(s[i]);
        //         }
        //     }
        // }
        // return st.size()/2;
        int i=0,j=s.size()-1,cnt=0,o=0,c=0;
        while(s[j]==']'){
            j-=1;
        }
        while(i<j){
            if(s[i]=='['){
                o+=1;
            }
            else{
               c+=1; 
            }
            if(c>o){
                c-=1;
                o+=1;
                j-=1;
                while(i<j and s[j]==']'){
                    j-=1;
                }
                cnt+=1;
            }
            i+=1;
        }
        return cnt;
    }
};