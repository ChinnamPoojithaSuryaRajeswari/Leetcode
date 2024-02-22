class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=0){
            pq.push((-1)*nums[i]);}
        }
        int count=0;
        while(!pq.empty()){
            int  p = (-1)*pq.top();
            while(!pq.empty()){
                cout<<pq.top()<<" ";
                pq.pop();
            }
            cout<<endl;
            for(int i=0;i<nums.size();i++){
                int q = nums[i]-p;
                if(q>0){
                    pq.push((-1)*q);
                }
                nums[i]-=p;
            }
            count+=1;
        }
        return count;
    }
};