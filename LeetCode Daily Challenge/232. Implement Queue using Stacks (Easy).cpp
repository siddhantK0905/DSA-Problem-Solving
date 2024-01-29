class MyQueue {
    stack<int> st;
public:
    MyQueue() {
        
    }

    void pushHelper(int x){
        if(st.size() == 0){
            st.push(x);
            return;
        }

        int data = st.top();
        st.pop();
        pushHelper(x);
        st.push(data);
        return;
    }
    
    void push(int x) {
        pushHelper(x);
    }
    
    int pop() {
        int val = st.top();
        st.pop();   
        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return (st.size() == 0);
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
