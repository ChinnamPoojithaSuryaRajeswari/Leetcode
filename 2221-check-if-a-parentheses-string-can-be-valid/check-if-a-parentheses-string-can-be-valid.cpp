class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) return false;
        int i=0;
        stack<int>ust;
        stack<int>lst;
        while(i<s.size()){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    lst.push(i);
                }
                else{
                    if(!lst.empty())lst.pop();
                    else if(!ust.empty())ust.pop();
                    else return false;;
                }
            }
            else{
                ust.push(i);
            }
            i++;
        }
        while(!lst.empty() and !ust.empty()){
            if(lst.top()<ust.top()){
                lst.pop();
                ust.pop();
            }
            else{
                return false;
            }
        }
        return ust.size()%2==0 && lst.empty();
    }
};