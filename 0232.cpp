class MyQueue {
    stack<int> sA, sB;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!sA.empty())
        {
            sB.push(sA.top());
            sA.pop();
        }
        sA.push(x);
        while (!sB.empty())
        {
            sA.push(sB.top());
            sB.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = sA.top();
        sA.pop();
        return temp;
    }

    /** Get the front element. */
    int peek() {
        return sA.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return sA.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */