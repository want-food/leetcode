#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> min_stk;
    MinStack() {
        min_stk.push(INT32_MAX);
    }

    void push(int val) {
        stk.push(val);
        min_stk.push(min(val, min_stk.top()));
    }

    void pop() {
        min_stk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
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

int main() {
    MinStack *minStack = new MinStack();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    cout << minStack->getMin() << endl;
}