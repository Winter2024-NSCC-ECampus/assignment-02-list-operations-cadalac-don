//
// Created by vaugh on 2025-02-13.
//

class Node {
public:
    Node(int data, Node *next, Node *prev)
        : data(data),
          next(next),
          prev(prev) {
    }

    Node(int value)
        : data(value), next(nullptr), prev(nullptr) {
    }

    int data;
    Node* next;
    Node* prev;
};



