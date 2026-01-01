class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size(),m=n;
        int c = 1;
        for(int i = n-1 ; i>=0 ; i--){
            c=(digits[i]+c)/10;
        }
        if(c>0){
            m+=1;
        }
        c=1;
        vector<int>res(m,0);
        for(int i=n-1 ; i>=0; i--){
            res[i] = (digits[i] + c)%10;
            c=(digits[i]+c)/10;
        }
        res[0] += c;
        return res;
    }
};