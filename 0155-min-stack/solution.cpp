class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long> s1;
    long long min;
    MinStack() {
        min=INT_MAX;
    }
    
    void push(int val) {
        long long value=val;
        if (s1.empty()){
            s1.push(value);
            min=value;
        }
        else{
            if (value<min)
            {
                s1.push(2*value-min);
                min=value;
            }
            else{
                s1.push(value);
            }
        }
    }
    
    void pop() {
        long long val=s1.top();
        if (!s1.empty()){
            if (val<min)
            {
                min=2*min-val;
            }
        }
            s1.pop();
    }
    
    int top() {
        if (!s1.empty() && s1.top()<min){
            return min;
        }
        return s1.top();
    }
    
    int getMin() {
        return min;
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
