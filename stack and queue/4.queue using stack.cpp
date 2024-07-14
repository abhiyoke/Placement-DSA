class MyQueue {
public:
    stack<int>s,s1;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        s1.push(x);
        while(!s1.empty()){
            s.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
       int c=s.top();
        s.pop();
        return c;
    }
    
    int peek() {
          int c=s.top();
        return c;
    }
    
    bool empty() {
        return s.empty();
    }
};
