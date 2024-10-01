class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>mpp;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                if(mpp[(-1)*(arr[i]%k)]!=0){
                    cnt+=1;
                    mpp[(-1)*(arr[i]%k)]-=1;
                    }
               else if(mpp[k-(arr[i]%k)]!=0){
                    mpp[k-(arr[i]%k)]-=1;
                    cnt+=1;
                    }
                else if(arr[i]%k==0){
                    if(mpp[0]!=0){
                        cnt+=1;
                        mpp[0]-=1;
                        }
                    else{
                        mpp[0]+=1;
                        }
                    }
                else{
                    mpp[arr[i]%k]+=1;
                    }
            }
            else {
              int res = (arr[i]%k);
                if(mpp[(-1)*res]!=0){
                    cnt+=1;
                    mpp[(-1)*res]-=1;
                    }
                else if(mpp[(-1)*(k+res)]!=0){
                    cnt+=1;
                    mpp[(-1)*(k+res)]-=1;
                  
                    }
                else{
                    mpp[res]+=1;
                    }
            }
           
        }
        cout<<cnt;
        if(cnt==arr.size()/2) return true;
        return false;
    }
};