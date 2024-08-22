class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
    //      stack<char>st;
    //     vector<int>vec;
    //     int flag=0,first=-1,p=0;
    //     for(int i=0;i<seq.size();i++){
    //         if(st.empty()){
    //             st.push(seq[i]);
    //             vec.push_back(0);
    //             flag=1;
    //             p=0;
    //             first=-1;
    //         }
    //         else{
    //             if(seq[i]=='('){
    //                 st.push(seq[i]);
    //                 vec.push_back(flag);
    //                 flag = flag^1;
    //                 first=-1;
    //                 p=0;
    //             }
    //             else{
    //                 flag=0;
    //                 if(first==-1){
    //                     first=1;
    //                     vec.push_back(p);
    //                     p=p^1;
    //                 }
    //                 else{
    //                     vec.push_back(p);
    //                     p=p^1;
    //                 }
    //             }
    //         }
    //     }
    //     return {0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0};
        stack<int>st;
        vector<int> ans(seq.size(),-1);
        int flag=0;
        for(int i=0;i<seq.size();i++){
            if(st.empty()){
                flag=0;
            }
            if(seq[i]=='('){
                st.push(i);
                flag=flag^1;
            }
            else{
                ans[st.top()]=flag;
                ans[i]=flag;
                flag=flag^1;
                st.pop();
            }
        }
        return ans;
    }
};