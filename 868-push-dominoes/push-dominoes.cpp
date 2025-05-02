class Solution {
public:
    string pushDominoes(string dominoes) {
        string answer = "";
        int i=0,j=0;
        while(i<dominoes.size()){
            if(dominoes[i]!='.')break;
            i++;
        }
        if(dominoes[i]=='L'){
            while(j<=i){
                answer += 'L';
                j++;
            }
        }
        else if(dominoes[i]=='R'){
            while(j<i){
                answer += '.';
                j++;
            }
            answer+='R';
        }
        else{
            while(j<dominoes.size()){
                answer+='.';
                j++;
            }
            return answer;
        }
        j=i;
        i++;
        int flag = 0;
        while(i<dominoes.size()){
            if(dominoes[i]!='.'){
                // cout<<dominoes[i]<<" "<<dominoes[j]<<endl;
                if(dominoes[i]=='R' and dominoes[j]=='L'){
                    j++;
                    while(j<i){
                        answer += '.';
                        j++;
                    }
                    j=i;
                    answer+=dominoes[i];
                    flag = 0;
                }
                else if(dominoes[i]=='R' and dominoes[j]=='R'){
                    j++;
                    while(j<=i){
                        answer += 'R';
                        j++;
                    }
                    j=i;
                }
                else if(dominoes[i]=='L' and dominoes[j]=='L'){
                    j++;
                    while(j<=i){
                        answer += 'L';
                        j++;
                    }
                    j=i;
                }
                else{
                    int k  = (i-j+1)/2;
                    int val = (i-j+1);
                    k=j+k;
                    j++;
                    while(j<k){
                        answer+='R';
                        j++;
                    }
                    if(val%2==1){
                        answer+='.';
                        j++;
                    }
                    while(j<=i){
                        answer += 'L';
                        j++;
                    }
                    j=i;
                }
            }
            i++;
        }
        if(dominoes[i-1]=='.'){        
            if(dominoes[j]=='L'){
                while(j<dominoes.size()-1){
                    answer +='.';
                    j++;
                }
            }
            else{
                while(j<dominoes.size()-1){
                    answer += ' R';
                    j++;
                }
            }
        }
        return answer;
    }
};