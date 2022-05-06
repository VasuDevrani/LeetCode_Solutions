class MyQueue {
public:
    stack<int>stk;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        stack<int>temp;
        
        while(stk.size()!=1)
        {
            temp.push(stk.top());
            stk.pop();
        }
        int t=stk.top();
        stk.pop();
        
        while(!temp.empty())
        {
            stk.push(temp.top());
            temp.pop();
        }
        return t;
    }
    
    int peek() {
        stack<int>temp;
        
        while(stk.size()!=1)
        {
            temp.push(stk.top());
            stk.pop();
        }
        int t=stk.top();
        
        while(!temp.empty())
        {
            stk.push(temp.top());
            temp.pop();
        }
        return t;
    }
    
    bool empty() {
        return stk.size()==0;
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