class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int su=0,k,p;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                su-=st.top();
                st.pop();
            }
            else if(operations[i]=="D"){
                k = st.top();
                su+=(2*k);
                st.push(k*2);
            }
            else if(operations[i]=="+"){
                k = st.top();
                st.pop();
                p = st.top();
                st.push(k);
                st.push(k+p);
                su+=k+p;
            }
            else{
                // if(operations[i][0]!='-'){
                // su = su + int(operations[i][0])-int('0');
                //     st.push(int(operations[i][0])-int('0'));
                // }
                // else{
                //     su = su - (int(operations[i][1])-int('0'));
                //     st.push((-1)*(int(operations[i][1])-int('0')));
                // }
                su+=stoi(operations[i]);
                st.push(stoi(operations[i]));
            }
        }
        return su;
    }
};