class Solution {
public:
    bool rotateString(string s, string goal) {
        int i=0;
        while(i<s.size()){
            s+=s[0];
            s.erase(s.begin());
            if(s==goal)return true;
            i+=1;
        }
        return false;
    }
};