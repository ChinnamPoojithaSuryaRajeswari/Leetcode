class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int flag=-1;
        for(int i=0;i<num.size();i++){
            if(int(num[i])-int('0') < change[int(num[i])-int('0')]){
                flag = i;
                break;
            }
        }
        // cout<<flag<<" ";
        if(flag==-1)return num;
        while(flag < num.size()){
            if(int(num[flag])-int('0') <= change[int(num[flag])-int('0')]){
                num[flag] = '0'+change[int(num[flag])-int('0')];
            }
            else{
                break;
            }
            flag++;
        }
        return num;
    }
};