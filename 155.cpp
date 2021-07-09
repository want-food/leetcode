/*************************************************************************
	> File Name: 155.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Thu Jul  8 09:56:14 2021
 ************************************************************************/

#include<iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
	stack<int> stk, stk_min;
	// int Min;
    MinStack() {
		stk.push(INT32_MAX);
		stk_min.push(INT32_MAX);
		// Min = INT32_MAX;
    }
    
    void push(int val) {
		// if(val < Min){
		// 	Min = val;
		// }
		stk.push(val);
		if(val < stk_min.top()) {
			stk_min.push(val);
		}
		else  {
			stk_min.push(stk_min.top());
		}
    }
    
    void pop() {
		stk.pop();
		stk_min.pop();
    }
    
    int top() {
		return stk.top();
    }
    
    int getMin() {
		return stk_min.top();
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

int main(){
	MinStack *minStack = new MinStack();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	cout << minStack->getMin() << endl;  
	minStack->pop();
	cout << minStack->top() << endl;  
	cout << minStack->getMin()<< endl;
}