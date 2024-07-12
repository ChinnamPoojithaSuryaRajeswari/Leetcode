class Solution {
public:
    int maximumGain(string si, int x, int y) {
        string m="ab",p="ba",sam="";
        int temp;
        vector<char>s;
        for(int i=0;i<si.size();i++){
            s.push_back(si[i]);
            }
        if(x<y){
            sam=m;
            m=p;
            p=sam;
            temp=x;
            x=y;
            y=temp;
}
       
        int i=0,c=0;
        while(i+1<s.size()){
            sam=s[i];
           sam=sam+s[i+1];
            if(sam==m){
                c+=x;
                s.erase(s.begin()+i);
              s.erase(s.begin()+i);
                if(i!=0){
                i-=1;}
            }
            else{
                i+=1;
                }
        }
        i=0;
        while(i<s.size() and i+1<s.size()){
            sam=s[i];
            sam=sam+s[i+1];
            if(sam==p){
                c+=y;
                s.erase(s.begin()+i);
              s.erase(s.begin()+i);
                if(i!=0){
                i-=1;}
            }
            else{
                i+=1;
                }
        }
        return c;
    }
};