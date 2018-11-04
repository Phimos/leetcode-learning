class MinStack {
public:
    stack<int> nums, minval;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        nums.push(x);
        if (minval.empty())
            minval.push(x);
        else
            minval.push(min(minval.top(), x));
    }

    void pop() {
        nums.pop();
        minval.pop();
    }

    int top() {
        return nums.top();
    }

    int getMin() {
        return minval.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */