class Solution {
public:
    int PairCount(vector<int>&nums, int key){
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[j]-nums[i] > key){
                break;
            }
            j+=1;
        }
        int prcnt = (j*(j-1))/ 2;
        cout<<prcnt<<endl;
        while(j<nums.size()){
            if(nums[j]-nums[i] <= key){
                prcnt+=(j-i);
                j+=1;
            }
            if(nums[j]-nums[i] > key){
                i+=1;
                // prcnt+= (j-i);
            }
        }
        return prcnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s = nums.size()-1,l=nums[0]-nums[1],h=nums[s]-nums[0],m,pircnt;
        while(l <= h){
            m = (l+h)/2;
            pircnt = PairCount(nums,m);
            cout<<l<<" "<<h<<" "<<m<<" "<<pircnt<<endl;
            if(pircnt < k){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return l;
    }
};