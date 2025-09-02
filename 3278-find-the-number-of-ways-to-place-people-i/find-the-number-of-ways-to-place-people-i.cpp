class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // int ans=0;
        // for(int i=0;i<points.size();i++){
        //     for(int j=i+1;j<points.size();j++){
        //         int flag = 0;
        //         if(points[i][0]>=points[j][0] and points[i][1]<=points[j][1]){
        //             for(int k=0;k<points.size();k++){
        //                 int a = points[i][0], b = points[i][1], c = points[j][0], d = points[j][1], e = points[k][0], f = points[k][1];
        //                 if(k!=i and k!=j){
        //                     if(a>=e and c<=e and b<=f and d>=f){
        //                         if((abs(f-b)*abs(e-c)) == (abs(f-d)*abs(e-a))){
        //                            flag=1;
        //                         } 
        //                     }
        //                 }
        //             }
        //             if(!flag) ans++;
        //         }
        //     }
        // }
        // return ans;
        int n = points.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];
                if(ax <= bx && ay >= by){
                    bool valid = true;
                    for(int k=0; k<n; k++){
                        if(k == i || k == j) continue;
                        int ex = points[k][0], ey = points[k][1];
                        if(ax <= ex && ex <= bx && by <= ey && ey <= ay){
                            valid = false;
                            break;
                        }
                    }
                    if(valid) ans++;
                }
            }
        }
        return ans;
    }
};