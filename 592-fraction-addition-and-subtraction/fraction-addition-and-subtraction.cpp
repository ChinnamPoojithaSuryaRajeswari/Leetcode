class Solution {
public:
    int gcd(int a, int b){
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
    }
    string fractionAddition(string expression) {
        string str="";
        str+=expression[0];
        vector<int>numerator;
        vector<int>denomenator;
        for(int i=1;i<expression.size();i++){
            if(expression[i]=='/'){
                numerator.push_back(stoi(str));
                str="";
            }
            else if(int(expression[i])==int('+') or int(expression[i])==int('-')){
                denomenator.push_back(stoi(str));
                str="";
                str+=expression[i];
            }
            else{
                str+=expression[i];
            }
        }
        denomenator.push_back(stoi(str));
        int a = denomenator[0],lcm=a;
        for(int i=1;i<denomenator.size();i++){
            lcm = lcm*denomenator[i];
            a = gcd(a,denomenator[i]);
            lcm = lcm/a;
        }
        int ans =0;
        for(int i=0;i<numerator.size();i++){
            ans+=(numerator[i]*(lcm/denomenator[i]));
        }
        int k=1;
        for(int i=max(ans,lcm);i>=1;i--){
            if(ans%i==0 and lcm%i==0){
                k = i;
                break;
            }
        }
        ans = ans/k;
        lcm = lcm/k;
        string res = "";
        res+=to_string(ans);
        res+='/';
        res +=to_string(lcm);
        if(ans==0){
            return "0/1";
        }
        return res;  
    }
};