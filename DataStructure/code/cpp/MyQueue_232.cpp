class MyQueue {
public:
    // 初始化两个栈，模拟队列
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {
    }
    
    void push(int x) {
        stIn.push(x); // 将数据放入尾部, 先进先出
    }
    
    int pop() {
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int pop_ = stOut.top();
        stOut.pop();
        return pop_;
    }
    
    int peek() {
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }
    
    bool empty() {
        if (stOut.empty() && stIn.empty())
            return true;
        return false;
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
