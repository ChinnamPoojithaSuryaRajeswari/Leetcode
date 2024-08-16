class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min1=INT_MAX,max1=INT_MIN,flag=0,temp;
        for(int i=0;i<arrays.size();i++){
            if(arrays[i][0] < min1){
                if(flag==2 or flag==1){
                    flag=0;
                }
                min1 = arrays[i][0];
                flag+=1;
            }
            if(arrays[i][arrays[i].size()-1] > max1){
                if(flag==2){
                    flag=0;
                }
                max1 = arrays[i][arrays[i].size()-1];
                flag+=1;
                if(flag==2){
                    temp = i;
                }
            }
        }
        cout<<flag;
        if(flag!=2){
            return max1-min1;
        }
        else{
            int min2=INT_MAX,max2=INT_MIN,i=0;
            while(i<arrays.size()){
                if(i!=temp){
                    if(arrays[i][0] < min2){
                        min2 = arrays[i][0];
                    }
                    if(arrays[i][arrays[i].size()-1] > max2){
                        max2 = arrays[i][arrays[i].size()-1];
                    }
                }
                i+=1;
            }
            cout<<min1<<" "<<max1<<" "<<min2<<" "<<max2<<" ";
            return max(max2 - min1, max1 - min2);
        }
    }
};