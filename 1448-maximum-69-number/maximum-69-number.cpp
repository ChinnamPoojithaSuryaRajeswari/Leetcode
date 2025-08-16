class Solution {
public:
    int maximum69Number (int num) {
        int ans=0;
        while(num){
            ans = ans*10+(num%10);
            num=num/10;
        }
        num=0;
        int flag=1;
        while(ans){
            if(ans%10==6 and flag==1){
                flag = 0; 
                num = num*10+9;
            }
            else{
                num = num*10+(ans%10);
            }
            ans = ans/10;
        }
        return num;
    }
};