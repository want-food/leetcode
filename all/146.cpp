#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node {
public:
    Node *pre, *next;
    int key, val;
    Node(): key(0), val(0), pre(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int size, Cap;
    Node *head = new Node();
    Node *tail = new Node();
    unordered_map<int, Node *> map;

public:
    LRUCache(int capacity) {
        size = 0;
        Cap = capacity;
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if(map.find(key) != map.end()) {
            Node *node = map[key];
            node->pre->next = node->next;
            node->next->pre = node->pre;
            node->pre = head;
            node->next = head->next;
            head->next->pre = node;
            head->next = node;
            return map[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            Node *node = map[key];
            node->val = value;
            node->pre->next = node->next;
            node->next->pre = node->pre;
            node->pre = head;
            node->next = head->next;
            head->next->pre = node;
            head->next = node;
        }
        else {
            if(size < Cap) {
                Node *node = new Node(key, value);
                node->pre = head;
                node->next = head->next;
                head->next->pre = node;
                head->next = node;
                size++;
                map[key] = node;
            }
            else {
                Node *node = tail->pre;
                map.erase(node->key);
                node->pre->next = tail;
                tail->pre = node->pre;
                node->key = key;
                node->val = value;
                node->pre = head;
                node->next = head->next;
                head->next->pre = node;
                head->next = node;
                map[key] = node;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache *lru = new LRUCache(2);
    lru->put(1, 1);
    lru->put(2, 2);
    cout << lru->get(1) << endl;
    lru->put(3, 3);
    cout << lru->get(2) << endl;
    lru->put(4, 4);
    cout << lru->get(1) << endl;
    cout << lru->get(3) << endl;
    cout << lru->get(4) << endl;
}