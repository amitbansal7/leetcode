//Runtime: 3 ms
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>A;
    stack<int>B;
    MyQueue() {

    }
    void transfer()
    {
        while(!A.empty())
        {
            B.push(A.top());
            A.pop();
        }
    }
    /** Push element x to the back of queue. */
    void push(int x) {
        A.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = peek();
        B.pop();

        return t;
    }

    /** Get the front element. */
    int peek() {
        if(B.empty())
            transfer();
        return B.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return A.empty() && B.empty();
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
