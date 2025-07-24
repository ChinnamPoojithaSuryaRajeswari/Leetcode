class Solution {
public:
    void help(vector<string>&p,vector<string>& answer,int k,string &digits,string res){
        if(k>=digits.size()){
            if(res!="") answer.push_back(res);
            return;
        }
        for(int pooji = 0 ; pooji < p[int(digits[k])-int('0')].size();pooji++){
            help(p,answer,k+1,digits,res+p[int(digits[k])-int('0')][pooji]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>p(10,"");
        vector<string>answer;
        p[2] = "abc";
        p[3] = "def";
        p[4] = "ghi";
        p[5] = "jkl";
        p[6] = "mno";
        p[7] = "pqrs";
        p[8] = "tuv";
        p[9] = "wxyz";
        help(p,answer,0,digits,"");
        return answer;
    }
};