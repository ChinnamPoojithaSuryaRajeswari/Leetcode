class Solution {
public:
    int passThePillow(int n, int time) {
        if(n==1) return 1;
        int k = time%(n-1);
        if(int(time/(n-1))%2==0){
            return k+1;
        }
        else{
            return (n)-k;
        }
    }
};