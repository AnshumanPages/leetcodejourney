class MinStack {
public:
    stack<int> st;
    stack<int> mini;

    MinStack() {
        mini.push(INT_MAX);
    }

    void push(int val) {
        st.push(val);
        mini.push(min(val, mini.top()));
    }

    void pop() {
        st.pop();
        mini.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mini.top();
    }
};