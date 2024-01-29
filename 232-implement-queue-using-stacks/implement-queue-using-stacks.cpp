class MyQueue {
public:
    stack<int>a;
    stack<int>b;
    MyQueue() {
        a={};
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while(!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
        int q = b.top();
        b.pop();
        while(!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
        return q;
    }
    
    int peek() {
        while(!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
        int q = b.top();
        while(!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
        return q;
    }
    
    bool empty() {
        if(a.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */