class MyQueue {
    stack<int> input;    // holds newly pushed elements, most recent on top
    stack<int> output;   // holds elements in FIFO-ready order, front of queue on top

public:
    MyQueue() {}

    void push(int x) {
        input.push(x);   // new elements always go here, never touch output directly
    }

    int pop() {
        peek();               // ensures output has the front element ready
        int front = output.top();
        output.pop();
        return front;
    }

    int peek() {
        if (output.empty()) {           // only refill when output is fully drained
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};
