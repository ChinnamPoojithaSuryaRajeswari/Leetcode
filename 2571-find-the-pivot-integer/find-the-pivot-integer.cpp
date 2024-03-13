class Solution {
public:
    int pivotInteger(int n) {
        int i=0,j=n;
        int s=0,su=0;
        while(i<j){
            if(s>su){
                su+=j;
                j-=1;
            }
            else{
                s+=i;
                i+=1;
            }
            if(i==j){
                if(s==su){
                    return i;
                }
            }
            // cout<<s<<" "<<su<<" ";
        }
        return -1;
    }
};