//
// Created by vaugh on 2025-02-13.
//
#include <iostream>
#include "Node.cpp"
using namespace std;

class List {
public:
    //This is head = first and tail = first
    Node* first = nullptr;
    Node* last = nullptr;

    void append(int value) {
        Node *newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
        }  else {
            newNode->prev = last;
            last->next = newNode;
        }
        last = newNode;
    }

    void prepend(int value) {
        Node *newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        }  else {
            newNode-> next = first;
            first->prev = newNode;
            first = newNode;
        }
    }

    Node *insertPos(int pos, int data) {

        if (pos < 1) {
            return nullptr;
        }

        if (pos == 1) {
            Node *newNode = new Node(data);
            newNode->next = first;
            first = newNode;
            return newNode;
        }

        Node *node = first;

        for (int i = 1; i < pos - 1 && node != nullptr; i++) {
            node = node->next;
        }

        if (node == nullptr)
            return nullptr;

        Node *newNode = new Node(data);

        // update the next pointers
        newNode->next = node->next;
        node->next = newNode;

        return first;
    }

    int size() {
        int count = 1;
        Node* current = first;
        while (current != last) {
            count++;
            current = current->next;
        }
        return count;
    }

    Node* index(int value) {
        if (value < 0) {
            cout << "Enter Valid Number." << endl;
            return nullptr;
        }
        if(value > size()) {
            cout << "Index Value is out of Bounds." << endl;
            return nullptr;
        }
        int count = 0;
        Node* current = first;
        while (current != nullptr) {
            if (count == value) {
                return current;
            }
            count++;
            current = current->next;
        }

        cout << "Enter a smaller number." << endl;
        return nullptr;
    }


    void deleteHead() {
        if (first == nullptr) {
            return;
        }

        Node* temp = first;
        first = first->next;

        if (first) {
            first->prev = nullptr;
        }
        else {
            last = nullptr;
        }
        delete temp;
    }


    void deleteIndexedNode(int position) {
        if (first == nullptr || position < 1) {
            cout << "Invalid position or empty list." << endl;
            return;
        }

        Node* current = first;
        // Case 1: Deleting the first node
        if (position == 1) {
            deleteHead();
            return;
        }

        // Traverse to the node at the given position
        for (int i = 1; i < position && current != nullptr; i++) {
            current = current->next;
        }

        // If position is beyond the list length
        if (current == nullptr) {
            cout << "Position out of bounds." << endl;
            return;
        }

        // Case 2: If the node to be deleted is NOT the last one
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        else {
            // If last node is deleted, update `last`
            last = current->prev;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }

        //delete current; // Free memory
    }

    void lastPop() {
        if (last == nullptr) {
            return;
        }

        if(first == last){
            first = nullptr;
            last = nullptr;
        }
        else {
            last = last->prev;
            last->next = nullptr;
        }
    }

    List** splitList() {
        int fullSize = size();
        int halfSize = size()/2;
        int firstHalf, secondHalf;
        if(fullSize % 2 == 1) {
            firstHalf = fullSize/2+1;
            secondHalf = size()-firstHalf;
        } else {
            firstHalf = halfSize;
            secondHalf = halfSize;
        }

        List** lists = new List*[2];
        lists[0] = new List(); // first half
        lists[1] = new List(); // second half
        Node* current = first;

        for(int i = 0; i < firstHalf; i++) {
            lists[0]->append(current->data);
            current = current->next;
        }

        for(int i = firstHalf+1; i <= firstHalf+secondHalf; i++) {
            lists[1]->append(current->data);
            current = current->next;
        }
        return lists;
    }

    void bubbleSort() {

        bool swapped = true;
        // Continue looping until no swaps are made in a complete pass.
        while (swapped) {
            swapped = false;
            Node* current = first;
            // Traverse the list comparing each pair of adjacent nodes.
            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    // Swap the data values of the two nodes.
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
        }
    }

    void printInfo() {
        int thisSize = size();
        for(int i = 0; i < thisSize; i++ ) {
            cout << index(i)->data << endl;
        }
    }

    void listCopy(List* oldList) {
        Node* current = oldList->first;
        while (current != nullptr) {
            append(current->data);
            current = current->next;
        }
    }

    void merge(List* oldList, List* otherList) {
        // this function assumes both input lists are already sorted
        Node* current1 = oldList->first;
        Node* current2 = otherList->first;

        // compare elements from both lists and add the smaller one
        while(current1 != nullptr && current2 != nullptr){
            if(current1->data <= current2->data){
                append(current1->data);
                current1 = current1->next;
            } else {
                append(current2->data);
                current2 = current2->next;
            }
        }

        // Add remaining elements from first list (if any)
        while (current1 != nullptr){
            append(current1->data);
            current1 = current1->next;
        }

        while (current2 != nullptr){
            append(current2->data);
            current2 = current2->next;
        }
    }
};