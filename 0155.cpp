class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minStack;
    MinStack() {

    }

    void push(int val) {
        stack.push(val);
        if (minStack.empty() || val < minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        stack.pop();
        minStack.pop();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
