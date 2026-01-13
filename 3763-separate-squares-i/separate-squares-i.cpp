class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l=INT_MAX,h=INT_MIN,ans=INT_MAX;
        for(int i=0;i<squares.size();i++){
            l = min(l,squares[i][1]*1.0);
            h = max(h,(squares[i][1]+squares[i][2])*1.0);
        }
        int precesion = 0.0000001;
        for(int p=0;p<100;p++){
            double m  = (l+h)/2;
            long double leftArea = 0,rightArea = 0;
            for(int i=0;i<squares.size();i++){
                long double x = squares[i][2],y=squares[i][1];
                if(squares[i][1]+squares[i][2] <= m){
                    leftArea += (x*x);
                }
                else if(squares[i][1]>m){
                    rightArea += (x*x);
                }
                else{
                    leftArea += ((m-y)*x);
                    rightArea += ((y+x-m)*(x));
                }
            }
            // if(leftArea == rightArea)cout<<"adsf";
            // cout<<leftArea<<" "<<rightArea<<" "<<l<<" "<<h<<endl;
            if(leftArea >= rightArea){
                ans = min(ans,m);
                h = m - precesion;
            }
            else{
                l = m + precesion;
            }
        }
        return ans;
    }
};