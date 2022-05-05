class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int t= q1.front();
        q1.pop();
        q1=q2;
        while(!q2.empty())
        {
            q2.pop();
        }
        return t;
    }
    
    int top() {
        
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int t= q1.front();
        q2.push(q1.front());
        q1=q2;
        while(!q2.empty())
        {
            q2.pop();
        }
        return t;
    }
    
    bool empty() {
        return q1.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */