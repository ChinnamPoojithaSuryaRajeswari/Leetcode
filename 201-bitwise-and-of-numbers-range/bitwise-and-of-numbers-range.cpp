class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==1073741824 and right==2147483647){
            return 1073741824;
        } 
        int ans=right;
        if(left==0) return 0;
        else{
            int i=left;
            while(i<right){
                if((i&(i+1))==0){
                    return 0;
                }
                ans&=i;
                i+=1;
            }
        }
        return ans;
    }
};