// Runtime: 29 ms
class MinStack {
private:
    stack<int>min;
    stack<int>Stack;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        Stack.push(x);
        if(min.empty() || min.top() >= x)
            min.push(x);
    }

    void pop() {
        int x = Stack.top();
        Stack.pop();
        if(x == min.top())
            min.pop();
    }

    int top() {
        return Stack.top();
    }

    int getMin() {
        return min.top();
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
