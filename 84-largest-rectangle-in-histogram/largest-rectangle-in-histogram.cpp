class Solution {
public:
    vector<pair<int,int>>prev;
    vector<pair<int,int>>nxt;
    void call(vector<int>& heights){
        stack<pair<int,int>>st;
        int i=heights.size()-1;
        while(i>=0){
            if(st.empty()){
                prev.push_back({heights[i],heights.size()-1});
                st.push({heights[i],i});
            }
            else{
                while(!st.empty()){
                    if(st.top().first>=heights[i]){
                        st.pop();
                    }
                    else{
                        break;
                    }
                }
                if(st.empty()){
                    prev.push_back({heights[i],heights.size()-1});
                    st.push({heights[i],i});
                }
                else{
                    prev.push_back({st.top().first,st.top().second-1});
                    st.push({heights[i],i});
                }
            }
            // cout<<prev[prev.size()-1].first<<" "<<prev[prev.size()-1].second<<" ";
            i--;
        }
        cout<<endl;
        while(!st.empty())st.pop();
        i=0;
        while(i<heights.size()){
            if(st.empty()){
                nxt.push_back({heights[i],0});
                st.push({heights[i],i});
            }
            else{
                while(!st.empty()){
                    if(st.top().first>=heights[i]){
                        st.pop();
                    }
                    else{
                        break;
                    }
                }
                if(st.empty()){
                    nxt.push_back({heights[i],0});
                    st.push({heights[i],i});
                }
                else{
                    nxt.push_back({st.top().first,st.top().second+1});
                    st.push({heights[i],i});
                }
            }
            // cout<<nxt[i].first<<" "<<nxt[i].second<<" ";
            i++;
        }
        reverse(prev.begin(),prev.end());
    }
    int largestRectangleArea(vector<int>& heights) {
        call(heights);
        int maxArea = 0;
        cout<<endl;
        for(int i=0;i<prev.size();i++){
            // cout<<heights[i]*(nxt[i].second-prev[i].second-1)<<" ";
            maxArea = max(maxArea,(heights[i]*(prev[i].second-nxt[i].second+1)));
        }
        return maxArea;
    }
};