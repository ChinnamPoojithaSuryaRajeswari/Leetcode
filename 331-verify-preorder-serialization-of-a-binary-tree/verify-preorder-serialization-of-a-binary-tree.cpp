class Solution {
public:
    bool isValidSerialization(string preorder) {
       stack<pair<string,int>>st;
       int i=0;
       stringstream ss(preorder);
       vector<string>vec;
       string res;
       while(getline(ss,res,','))vec.push_back(res);
       if(vec[0]!="#")st.push({vec[0],0});
    //    for(auto it:vec)cout<<it<<" ";
       for( i = 1 ; i < vec.size() ; i+=1){
        if(st.empty())break;
            st.top().second+=1;
            // cout<<st.top().second<<" "<<st.top().first<<endl;
            if(st.top().second==2)st.pop();
            if(vec[i]!="#"){
                st.push({vec[i],0});
            }
       }

       if(i>=vec.size() and st.empty()) return 1;
       return 0;
    }
};