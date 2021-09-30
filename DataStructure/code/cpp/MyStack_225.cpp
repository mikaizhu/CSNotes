class MyStack {
public:
    queue<int> qIn;
    queue<int> qOut;

    MyStack() {

    }
    
    void push(int x) {
        qIn.push(x);
    }
    
    int pop() {
        int _size = qIn.size() - 1;
        while (_size--)
        {
            qOut.push(qIn.front()); // 利用qout进行备份
            qIn.pop();
        }

        // 最后会剩下一个元素
        int _pop = qIn.front();
        qIn.pop();
        _size = qOut.size();
        while (_size--)
        {
            qIn.push(qOut.front());
            qOut.pop();
        }
        return _pop;
    }
    
    int front() {
        return qIn.back();
    }
    
    bool empty() {
        return qIn.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */
