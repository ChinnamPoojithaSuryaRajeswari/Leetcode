class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        vector<int>span;
        int count=1,east=1,west=0,north=0,south=0,flag=0;
        while(ans.size()<(rows*cols)){
            if(flag==2){
                count+=1;
                flag=1;
            }
            else{
                flag+=1;
            }
            if(east==1){
                for(int i=0;i<count;i++){
                    if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols){
                        span.push_back(rStart);
                        span.push_back(cStart);
                        ans.push_back(span);
                        span.clear();
                    }
                     cStart+=1;
                }
                east=0;
                south=1;
            }
            else if(south==1){
                for(int i=0;i<count;i++){
                    if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols){
                        span.push_back(rStart);
                        span.push_back(cStart);
                        ans.push_back(span);
                        span.clear();
                    }
                     rStart+=1;
                }
                west=1;
                south=0;
            }
            else if(west==1){
                for(int i=0;i<count;i++){
                    if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols){
                        span.push_back(rStart);
                        span.push_back(cStart);
                        ans.push_back(span);
                        span.clear();
                    }
                    cStart-=1;
                }
                north=1;
                west=0;
            }
            else if(north==1){
                for(int i=0;i<count;i++){
                    if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols){
                        span.push_back(rStart);
                        span.push_back(cStart);
                        ans.push_back(span);
                        span.clear();
                    }
                    rStart-=1;
                }
                north=0;
                east=1;
            }
        }
        return ans;
    }
};