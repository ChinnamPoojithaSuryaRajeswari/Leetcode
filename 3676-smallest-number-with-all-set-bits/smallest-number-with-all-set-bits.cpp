class Solution {
public:
    int smallestNumber(int n) {
        for(int i=n;i<=10000;i++){
            if(((i+1)&i)==0){
                return i;
            }
        }
        return -1;
    }
};