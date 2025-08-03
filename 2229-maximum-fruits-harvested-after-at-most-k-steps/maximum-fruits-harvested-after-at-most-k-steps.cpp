class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // int i=0,j,ans=0,res = 0;
        // map<int,int>mpp;
        // for(int i=0;i<fruits.size();i++){
        //     mpp[fruits[i][0]]=fruits[i][1];
        // }
        // if(k<startPos){
        //     i = startPos-k;
        // }
        // else{
        //     i=0;
        // }
        // j=i;
        // int val = k;
        // while(1){
        //     if(j<=startPos){
        //         res+=mpp[j];
        //         j++;
        //     }
        //     else {
        //         if((startPos-i)*2+(j-startPos)<=k){
        //             j++;
        //             res+=mpp[j];
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // ans = max(ans,res);
        // if(i==j)return ans;
        // while(j<=startPos+val){
        //     if(i<startPos){
        //         res-=mpp[i];
        //         i++;
        //     }
        //     // cout<<res<<" "<<i<<" "<<j<<endl;
        //     if((startPos-i)*2+(j-startPos)<=k){
        //         res+=mpp[j];
        //         j++;
        //     }
        //     ans = max(ans,res);
        // }
        // return ans;
        int n=200001;
        vector<int>vec(n,0);
        for(int i = 0 ; i < fruits.size(); i++){
            vec[fruits[i][0]]=fruits[i][1];
        }
        if(k==0) return vec[startPos];
        for(int i=1;i<n;i++){
            vec[i]+=vec[i-1];
        }
        int ans=0;
        int left=1,right=1;
        while(left<=k && startPos-left>=0){
            int leftFruits=vec[startPos],rightFruits=0;
            if(startPos-left-1>=0){
                leftFruits-=vec[startPos-left-1];
            }
            right=k-2*left;
            if(right>0){
               if(startPos+right<n) rightFruits=vec[right+startPos]-vec[startPos];
               else rightFruits=vec[n-1]-vec[startPos];
            }
            ans=max(ans,rightFruits+leftFruits);
            left+=1;
        }
        left=1;
        right=1;
        while(right<=k && startPos+right<n){
            int rightFruits=vec[startPos+right],leftFruits=vec[startPos];
            rightFruits -=vec[startPos];
            left=k-2*right;
            if(left>0){
                if(startPos-left-1>=0) leftFruits-=vec[startPos-left-1];
            }
            else{
                if(startPos-1>=0) leftFruits-=vec[startPos-1];
            }
            ans=max(ans,rightFruits+leftFruits);
            right+=1;
        }
        return ans;
    }
};