class Solution {
public:
    void rec(int n,vector<string>&res,string s){
        if(n==0){
            res.push_back(s);
            return;
        }
        if(s.size()==0){
            rec(n-1,res,s+'a');
            rec(n-1,res,s+'b');
            rec(n-1,res,s+'c');
        }
        else{
            if(s[s.size()-1]=='a'){
                rec(n-1,res,s+'b');
                rec(n-1,res,s+'c');
            }
            else if(s[s.size()-1]=='b'){
                rec(n-1,res,s+'a');
                rec(n-1,res,s+'c');
            }
            else{
                rec(n-1,res,s+'a');
                rec(n-1,res,s+'b');
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        string s="";
        rec(n,res,s);
        if(k-1>res.size()-1)return "";
        sort(res.begin(),res.end());
        return res[k-1];
    }
};