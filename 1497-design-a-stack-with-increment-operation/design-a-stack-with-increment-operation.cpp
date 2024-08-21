class CustomStack {
public:
    int ms,k;
    vector<int>vec;
    CustomStack(int maxSize) {
        this->ms = maxSize;
    }
    void push(int x) {
        if(vec.size()<ms){
            vec.push_back(x);
        }
    }
    
    int pop() {
        if(vec.size()>0){
            k = vec[vec.size()-1];
            vec.pop_back();
            return k;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(k > vec.size()){
            int i=vec.size()-1;
            while(i>=0){
                vec[i] = vec[i]+val;
                i-=1;
            }
        }
        else{
            int i = 0;
            while(k){
                k-=1;
                vec[i] = vec[i]+val;
                i+=1;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */