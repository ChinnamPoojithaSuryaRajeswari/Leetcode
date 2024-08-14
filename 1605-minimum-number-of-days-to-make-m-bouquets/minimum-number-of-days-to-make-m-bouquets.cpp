class Solution {
public:
    int CntFlower(vector<int>& bloomyDay,int key,int k){
        int c=0,res=0,i=0;
        while(i<bloomyDay.size()){
            if(bloomyDay[i]<=key){
                // cout<<bloomyDay[i]<<" ";
                c+=1;
            }
            else{
                // cout<<c<<" ";
                res+=(c/k);
                // cout<<res<<" "<<c<<" "<<k<<" ";
                c=0;
            }
            i+=1;
        }
        res+=int(c/k);
        return res;
    }
    int minDays(vector<int>& bloomyDay, int m, int k) {
        int l=*min_element(bloomyDay.begin(),bloomyDay.end()),L=l;
        int h=*max_element(bloomyDay.begin(),bloomyDay.end()),cnt,H=h;
        vector<int>vec;
        while(l<=h){
            int M=(l+h)/2;
            // cout<<l<<" "<<h<<" "<<M<<" ";
            cnt = CntFlower(bloomyDay,M,k);
            // cout<<cnt<<endl;
            if(cnt==m){
                vec.push_back(M);
            }
            if(cnt < m){
                l = M+1;
            }
            else{
                // cout<<"Sdaf"<<endl;
                h = M-1;
            }
        }
        if(cnt>=m){
            if(l>=L and l<=H){
                return l;
            }
            else if(l>=L){
                return l-1;
            }
            else{
                l+=1;
            }
        }
        sort(vec.begin(),vec.end());
        if(vec.size()>0){
            return vec[0];
        }
        return -1;
    }
};