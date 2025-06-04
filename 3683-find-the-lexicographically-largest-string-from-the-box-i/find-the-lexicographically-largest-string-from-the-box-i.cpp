class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        char ch='a';
        for(int i = 0 ; i < word.size();i++){
            ch=max(ch,word[i]);
        }
        cout<<ch<<endl;
        string ans="";
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                int x=numFriends-i-1;
                if(x>0){
                    int s=word.size()-x-i;
                    ans=max(ans,word.substr(i,s));
                }
                else{
                    ans=max(ans,word.substr(i,word.size()-i));
                }
            }
        }
        return ans;
    }
};