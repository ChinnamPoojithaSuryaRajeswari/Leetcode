class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        int ans=0,val=0;
        for(auto i:directions){
            if(st.empty()){
                if(i=='L' and val == 1){
                    ans++;
                    // cout<<"hii  ";
                }
                else{
                    if(i!='L')st.push(i);
                }
            }
            else{
                if(i=='R'){
                     st.push('R');
                }
                else{
                    if(i=='L'){
                        val=1;
                        // cout<<st.top()<<" ";
                        if(st.top()=='R')ans+=2;
                        else ans++;
                        st.pop();
                        while(!st.empty()){
                            if(st.top()=='R')st.pop();
                            else break;
                            ans++;
                        }
                        st.push('S');
                        // cout<<"Hlo  ";
                    }
                    else if(i=='S'){
                        if(st.top()=='R'){
                            while(!st.empty()){
                                if(st.top()=='R'){
                                    ans++;
                                    st.pop();
                                }
                                else break;
                            }
                            val=1;
                            st.push('S');
                        }
                        else{
                            st.push('S');
                        }
                        // cout<<"loo  ";
                    }
                }
            }
        }
        return ans;
    }
};