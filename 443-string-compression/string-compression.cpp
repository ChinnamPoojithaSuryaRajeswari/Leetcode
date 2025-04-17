class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 1,i = 0,ans = 0,j=0;
        while(i<chars.size()-1){
            if(chars[i]==chars[i+1]){
                res++;
                i++;
            }
            else{
                ans++;
                chars[j++]=chars[i];
                if(res!=1){
                    int r = j;
                    while(res){
                        ans++;
                        chars[j++]=int('0')+(res%10);
                        res=res/10;
                    }
                    int k = j-1;
                    while(r<=k){
                        char temp = chars[k];
                        chars[k] = chars[r];
                        chars[r] = temp;
                        k--;
                        r++;
                    }
                }
                res = 1;
                i++;
            }
        }
        ans++;
        chars[j++]=chars[i];
        if(res!=1){
            int r = j;
            while(res){
                ans++;
                chars[j++]=int('0')+(res%10);
                res=res/10;
            }
            int k = j-1;
            while(r<=k){
                char temp = chars[k];
                chars[k] = chars[r];
                chars[r] = temp;
                k--;
                r++;
            }
        }
        return ans;
    }
};