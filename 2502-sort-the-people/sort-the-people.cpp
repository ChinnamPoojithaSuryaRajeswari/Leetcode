class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        string res;
        int temp;
        int c=0;
        for(int i=0;i<heights.size();i++){
            c=0;
            for(int j=0;j<heights.size()-i-1;j++){
                if(heights[j]<heights[j+1]){
                    temp = heights[j];
                    heights[j] = heights[j+1];
                    heights[j+1] = temp;
                    res = names[j];
                    names[j] = names[j+1];
                    names[j+1]= res;
                    c+=1;
                }
            }
            if(c==0){
                return names;
            }
        }
        return names;
    }
};