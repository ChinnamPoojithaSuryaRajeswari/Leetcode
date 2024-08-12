class KthLargest {
public:
    int l,count=0;
    vector<int> vec;
    priority_queue<int>pq;
    KthLargest(int k, vector<int>& nums) {
        this->l=k;
        this->vec = nums;
        while(!pq.empty()){
            pq.pop();
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
            count+=1;
            pq.push((-1)*vec[i]);
            if(count==l){
                break;
            }
            // cout<<pq.top()<<" ";
        }
    }
    int add(int val) {
        // cout<<pq.top()<<" ";
        if(count!=l){
            count+=1;
            pq.push((-1)*val);
        }
        else{
            if(pq.empty()){
                pq.push((-1)*val);
            }
            else if(pq.top()>(-1)*val){
                pq.pop();
                pq.push((-1)*val);
            }
        }
        return (-1)*pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */