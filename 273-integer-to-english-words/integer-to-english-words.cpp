class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        vector<string> resq;
        map<int,string>ones;
        map<int,string>tens;
        ones[1] = "One";
        ones[2] = "Two";
        ones[3] = "Three";
        ones[4] = "Four";
        ones[5] = "Five";
        ones[6] = "Six";
        ones[7] = "Seven";
        ones[8] = "Eight";
        ones[9] = "Nine";
        tens[2] = "Twenty";
        tens[3] = "Thirty";
        tens[4] = "Forty";
        tens[5] = "Fifty";
        tens[6] = "Sixty";
        tens[7] = "Seventy";
        tens[8] = "Eighty";
        tens[9] = "Ninety";
        string ans;
        map<int,string> lency;
        lency[1]="Thousand";
        lency[2]="Million";
        lency[3]="Billion";
        int len=0,k;
        map<int,string> speacial;
        speacial[1]="Eleven";
        speacial[2]="Twelve";
        speacial[3]="Thirteen";
        speacial[4]="Fourteen";
        speacial[5]="Fifteen";
        speacial[6]="Sixteen";
        speacial[7]="Seventeen";
        speacial[8]="Eighteen";
        speacial[9]="Nineteen";
        int p=0;
        while(num){
            if(len%3==0){
                cout<<p<<" "<<resq.size()<<endl;
                if(p==0 and resq.size()>2){
                    // cout<<resq.size();
                    resq.erase(resq.end()-2);
                }
                p=0;
                if(num%10!=0){
                    p=1;
                }
                k = num%10;
                if(lency[(len+1)/3]!=""){
                    resq.push_back(lency[(len+1)/3]);
                }
                if(k!=0){
                resq.push_back(ones[num%10]);
                }
            }
            else if(len%3==1){
                if(num%10!=0){
                    p=1;
                }
                if(num%10!=1){
                resq.push_back(tens[num%10]);
                }
                else{
                     if(k==0){
                         resq.push_back("Ten");
                     }
                    else{
                        resq.erase(resq.begin()+resq.size()-1);
                        resq.push_back(speacial[k]);
                    }
                }
            }
            else{
                if(num%10!=0){
                    p=1;
                }
                if(ones[num%10]!=""){
                resq.push_back("Hundred");
                resq.push_back(ones[num%10]);
                }
            }
            len+=1;
            num=num/10;
        }
        for(int i=resq.size()-1;i>=0;i--){
            if(resq[i]!=""){
                if(i!=resq.size()-1){
                    ans+=" ";
                }
                ans+=resq[i];
            }
        }
        return ans;
    }
};