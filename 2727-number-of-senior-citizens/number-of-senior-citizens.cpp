class Solution {
public:
    int countSeniors(vector<string>& details) {
        int senior=0;
        for(int i=0;i<details.size();i++){
            int age = 0;
            age = age*10+(int(details[i][11])-int('0'));
            age = age*10+(int(details[i][12])-int('0'));
            if(age>60){
                senior+=1;
            }
        }
        return senior;
    }
};