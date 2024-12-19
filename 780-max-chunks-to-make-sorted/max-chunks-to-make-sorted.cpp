class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        priority_queue<int>st;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            st.push(arr[i]);
            if(st.top()==i){
                cout<<st.top()<<" ";
                while(!st.empty()){
                    st.pop();
                }
                cnt+=1;
            }
        }
        return cnt;
    }
};