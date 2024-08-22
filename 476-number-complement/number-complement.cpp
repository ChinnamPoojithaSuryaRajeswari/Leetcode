class Solution {
public:
    int findComplement(int num) {
        long long k=0;
        while(1<<k <= num and k<31){
            num = num^(1<<k);
            k+=1;
        }
        return num;
    }
};