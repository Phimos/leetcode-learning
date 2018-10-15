class MyStack {
    queue<int> qA, qB;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        while (!qA.empty())
        {
            qB.push(qA.front());
            qA.pop();
        }
        qA.push(x);
        while (!qB.empty())
        {
            qA.push(qB.front());
            qB.pop();
        }
        return;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = qA.front();
        qA.pop();
        return temp;
    }

    /** Get the top element. */
    int top() {
        return qA.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return qA.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */