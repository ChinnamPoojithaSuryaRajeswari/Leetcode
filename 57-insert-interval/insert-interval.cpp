class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        int i=0,p=-1,ans,res=-1,req=-1;
        vector<vector<int>>vec;
        while(i<nums.size()){
            if(nums[i][0]<=newInterval[0] and nums[i][1]>=newInterval[0]){
                res=i;
                p=nums[i][0];
                break;
            }
            if(nums[i][0]>newInterval[0]){
                break;
            }
            i+=1;
        }
        int j=i,q=-1;
        i=0;
        while(i<nums.size()){
            if(nums[i][0]>newInterval[1]){
                // q = nums[i-1][1];
                req=i-1;
                break;
            }
            else if(nums[i][0]==newInterval[1]){
                q = i;
                req=i;
                break;
            }
            i+=1;
        }
        if(nums.size()==0){
            vec.push_back(newInterval);
            return vec;
        }
        cout<<res<<" "<<req;
        if(res==-1 and req==-1){
            if(nums[0][0]>=newInterval[0] and nums[nums.size()-1][1]<newInterval[1]){
                vec.push_back(newInterval);
                cout<<"h1";
                return vec;
            }
            if(nums[0][0]>newInterval[0] and newInterval[1]<nums[0][0]){
                nums.push_back(newInterval);
                sort(nums.begin(),nums.end());
                cout<<"h2";
               return nums;
            }
            if(nums[0][0]>newInterval[0]){
                nums[0][0] = newInterval[0];
                cout<<"h3";
                return nums;
            }
            if(newInterval[0]>nums[nums.size()-1][1]){
            nums.push_back(newInterval);
            sort(nums.begin(),nums.end());
                cout<<"h4";
            return nums;
            }
            else{
                i=0;
                while(nums[i][0]<newInterval[0]){
                    vec.push_back(nums[i]);
                    i+=1;
                }
                nums[i][0]=newInterval[0];
                int y = i;
                i=nums.size()-1;
                while(nums[i][1]>newInterval[1]){
                    i-=1;
                }
                if(i==nums.size()-1){
                    nums[y][1] = newInterval[1];
                    vec.push_back(nums[y]);
                    return vec;
                }
                else{
                    if(nums[i+1][0]>newInterval[1]){
                        nums[y][1]=newInterval[1];
                    }
                    else{
                        nums[y][1]=nums[i+1][1];
                    }
                }
                i+=1;
                vec.push_back(nums[y]);
                while(i<nums.size() and vec[vec.size()-1][1]<nums[i][0]){
                    vec.push_back(nums[i]);
                    i+=1;
                }
                return vec;
            }
        }
        else if(res==-1){
            if (newInterval[0]==newInterval[1]){
                nums.push_back(newInterval);
                sort(nums.begin(),nums.end());
                return nums;
            }
            i=0;
            if(req==0 and nums.size()!=1 and nums[0][0]<newInterval[0]){
                nums.push_back(newInterval);
                sort(nums.begin(),nums.end());
                return nums;
            }
            while(i<req)
            {
                vec.push_back(nums[i]);
                i+=1;
            }
            if(nums[i][0]>newInterval[0]){
                nums[i][0]=newInterval[0];
            }
            if(nums[i][1]<newInterval[1]){
                nums[i][1]=newInterval[1];
            }
            vec.push_back(nums[i]);
            i+=1;
            while(i<nums.size()){
                vec.push_back(nums[i]);
                i+=1;
            }
            sort(vec.begin(),vec.end());
            i=0;
            while(i<vec.size()-1){
                if(vec[i][1]<vec[i+1][0]){
                    nums.push_back(vec[i]);
                    i+=1;
                }
                else{
                    vec.erase(vec.begin()+i+1);
                }
            }
            return vec;
        }
        else if(req==-1){
             i=0;
             while(nums[i][0]!=nums[res][0]){
                 vec.push_back(nums[i]);
                 i+=1;
             }
             if(nums[nums.size()-1][1]<newInterval[1]){
                 nums[nums.size()-1][1]=newInterval[1];
                 nums[nums.size()-1][0]=p;
                 vec.push_back(nums[nums.size()-1]);
             }
            else{
                nums[nums.size()-1][0]=p;
                vec.push_back(nums[nums.size()-1]);
            }
             return vec;
        }
        else{
            i=0;
            while(i!=res){
                vec.push_back(nums[i]);
                i+=1;
            }
            if(nums[req][1]<newInterval[1]){
                nums[req][1]=newInterval[1];
            }
            nums[i][1]=nums[req][1];
            vec.push_back(nums[i]);
            while(i<=req){
                i+=1;
            }
            while(i<nums.size()){
                vec.push_back(nums[i]);
                i+=1;
            }
            return vec;
        }
        return vec;
    }
};