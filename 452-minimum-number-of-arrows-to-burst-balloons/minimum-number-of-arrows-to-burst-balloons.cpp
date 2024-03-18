class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int i=0,res=points[0][0],req=points[0][1],arrcnt=0;
        while(i<points.size()){
            cout<<points[i][0]<<" "<<points[i][1]<<" | ";
            i+=1;
        }
        i=0;
        while(i<points.size()){
            if(req<points[i][0]){
                    arrcnt+=1;
                if(i+1<points.size()){
                    req = points[i][1];
                }
            }
            if(req>points[i][1]){
                req = points[i][1];
            }
            i+=1;
        }
        return arrcnt+1;
    }
};