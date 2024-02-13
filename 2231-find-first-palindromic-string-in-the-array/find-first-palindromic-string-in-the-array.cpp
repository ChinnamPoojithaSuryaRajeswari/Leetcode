class Solution {
public:
    string firstPalindrome(vector<string>& words) {
          string y;
        for(auto it : words){
            int i = 0;
            int j = it.size()-1;
            string x = it;
            while(i < j){
                swap(x[i],x[j]);
                i++;
                j--;
            }
            if(x == it){
                y = x;
                break;
            }
       }
       return y;
    }
};