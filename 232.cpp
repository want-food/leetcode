/*************************************************************************
	> File Name: 232.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 08:51:32 2021
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
	stack<int> stk1, stk2;
	int top, size;
    MyQueue() {
		top = -1;
		size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		if(stk1.empty()) {
			top = x;
		}
		stk1.push(x);
		size++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		int res = top;
		while(!stk1.empty()) {
			stk2.push(stk1.top());
			stk1.pop();
		}
		stk2.pop();
		if(!stk2.empty())
			top = stk2.top();
		size--;
		while(!stk2.empty()) {
			stk1.push(stk2.top());
			stk2.pop();
		}
		return res;
    }
    
    /** Get the front element. */
    int peek() {
		return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		if(size == 0) return true;
		return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
	MyQueue* myQueue = new MyQueue();
	myQueue->push(1); // queue is: [1]
	cout << myQueue->peek() << endl; // return 1
	myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
	cout << myQueue->peek() << endl; // return 1
	cout << myQueue->pop() << endl; // return 1, queue is [2]
	cout << myQueue->empty() << endl; // return false
}