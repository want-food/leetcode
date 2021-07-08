#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// // solution 1:
// class LRUCache {
// public:
// 	vector<vector<int>> vec;
// 	int top;
// 	int Cap;
//     LRUCache(int capacity) {
// 		Cap = capacity;
// 		top = 0;
//     }
    
//     int get(int key) {
// 		for (int i = 0; i < top; i++) {
// 			if(vec[i][0] == key) {
// 				int tmp = vec[i][1];
// 				vec.erase(vec.begin() + i);
// 				vec.push_back({key, tmp});
// 				return tmp;
// 			}
// 		}
// 		return -1;
//     }
    
//     void put(int key, int value) {
// 		for (int i = 0; i < top; i++) {
// 			if(vec[i][0] == key) {
// 				vec.erase(vec.begin() + i);
// 				vec.push_back({key, value});
// 				return;
// 			}
// 		}
// 		if(top == Cap) {
// 			vec.erase(vec.begin());
// 			vec.push_back({key, value});
// 			return ;
// 		}
// 		vec.push_back({key, value});
// 		top++;
//     }
// };

// // solution 2:
// class Node {
// public:
// 	int key, value;
// 	Node *front, *back;	
// 	Node(): key(0), value(0), front(nullptr), back(nullptr) {};
// 	Node(int k, int v): key(k), value(v), front(nullptr), back(nullptr) {};
// };

// class LRUCache {
// public:
// 	Node *head;
// 	Node *tail;
// 	int top, Cap;
// 	LRUCache(int capacity) {
// 		head = new Node();
// 		tail = new Node();
// 		head->back = tail;
// 		tail->front = head;
// 		top = 0;
// 		Cap = capacity;
//     }
    
//     int get(int key) {
// 		Node *p = head->back;
// 		while(p != tail) {
// 			if(p->key == key) {
// 				p->front->back = p->back;
// 				p->back->front = p->front;
// 				p->back = head->back;
// 				head->back->front = p;
// 				head->back = p;
// 				p->front = head;
// 				return p->value;
// 			}
// 			p = p->back;
// 		}
// 		return -1;
//     }
    
//     void put(int key, int value) {
// 		Node *p = head->back;
// 		while(p != tail) {
// 			if(p->key == key) {
// 				p->value = value;

// 				p->front->back = p->back;
// 				p->back->front = p->front;
// 				p->back = head->back;
// 				p->front = head;
// 				head->back->front = p;
// 				head->back = p;
// 				return ;
// 			}
// 			p = p->back;
// 		}
// 		p = new Node(key, value);
// 		p->back = head->back;
// 		p->front = head;
// 		head->back->front = p;
// 		head->back = p;

// 		if(top == Cap) {
// 			tail->front->front->back = tail;
// 			tail->front = tail->front->front;
// 			return;
// 		}
// 		top++;
//     }
// };

// solution 3:
class Node {
public:
	int key, value;
	Node *front, *back;	
	Node(): key(0), value(0), front(nullptr), back(nullptr) {};
	Node(int k, int v): key(k), value(v), front(nullptr), back(nullptr) {};
};
class LRUCache {
public:
	unordered_map<int, Node*> map;
	int top = 0, Cap;
	Node *head = new Node(), *tail = new Node();
    LRUCache(int capacity) {
		Cap = capacity;
		head->back = tail;
		tail->front = head;
    }
    
    int get(int key) {
		auto it = map.find(key);
		if(it == map.end()) return -1;
		Node *p = map[key];
		p->front->back = p->back;
		p->back->front = p->front;
		p->back = head->back;
		p->front = head;
		head->back->front = p;
		head->back = p;
		return p->value;
    }
    
    void put(int key, int value) {
		auto it = map.find(key);
		if(it != map.end()) {
			Node *t = map[key];
			t->value = value;

			t->front->back = t->back;
			t->back->front = t->front;
			t->back = head->back;
			t->front = head;
			head->back->front = t;
			head->back = t;
			return;
		}

		if(top == Cap) {
			map.erase(map.find(tail->front->key));
			Node *t = tail->front;
			t->back->front = t->front;
			t->front->back = t->back;
			top--;
		}
		Node *p = new Node(key, value);
		map[key] = p;
		p->back = head->back;
		p->front = head;
		head->back->front = p;
		head->back = p;
		// tail->front->front->back = tail;
		// tail->front = tail->front->front;
		top++;
    } 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
	int n = 2;
	LRUCache *lRUCache = new LRUCache(n);
	lRUCache->put(1, 1); // 缓存是 {1=1}
	lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
	cout << lRUCache->get(1) << endl;    // 返回 1
	lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
	cout << lRUCache->get(2) << endl;    // 返回 -1 (未找到)
	lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
	cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
	cout << lRUCache->get(3) << endl;    // 返回 3
	cout << lRUCache->get(4) << endl;    // 返回 4
}