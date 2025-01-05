class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>v;
        for(int i=0;i<s.size();i++){
            v.push_back(0);
        }
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==0){
                v[shifts[i][0]]-=1;
                if(shifts[i][1]+1<=v.size()-1){
                    v[shifts[i][1]+1]+=1;
                }
            }
            else{
                v[shifts[i][0]]+=1;
                if(shifts[i][1]+1<=v.size()-1){
                    v[shifts[i][1]+1]-=1;
                }
            }
        }
        int ps=0;
        string res="";
        for(int i=0;i<s.size();i++){
            ps+=v[i];
            if(ps>=0){
                if(ps==0){
                    res+=s[i];
                }
                else{
                    int x=s[i];
                    x-=96;
                    x+=ps;
                    x=x%26;
                    x+=96;
                    if(x==96){
                        res+='z';
                    }
                    else{
                        res+=x;
                    }
                }
            }
            else{
                int x=s[i]-96;
                int te=ps*-1;
                te=te%26;
                if(x>=te){
                    x-=te;
                    x+=96;
                    if(x==96){
                        res+='z';
                    }
                    else{
                        res+=x;
                    }
                }
                else{
                    te-=x;
                    te=26-te;
                    te+=96;
                    res+=te;
                }
            }
        }
        return res;
    }
};