class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int k = int(coordinates[0])-int('a');
        int p = int(coordinates[1])-int('1');
        if(k%2==0){
            if(p%2!=0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(p%2!=0){
                return false;
            }
            else{
                return true;
            }
        }
    }
};