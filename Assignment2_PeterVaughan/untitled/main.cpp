#include <iostream>
#include "List.cpp"
using namespace std;

int main()
{
    List list;
    string a;

    //prepend - insert at the beginning
    list.prepend(13);
    cout << list.first->data << endl << endl;

    //append - insert at the end
    list.append(78);
    list.append(5);
    cout << list.first->data << endl;
    cout << list.last->data << endl << endl;

    //add value at given index
    cout << "Size before insert: " << list.size() << endl;
    int data = 12, pos = 2;
    list.insertPos(pos, data);
    cout << "Size after insert: " << list.size() << endl << endl;

    //print everything to verify all the info
    cout<< "Print numbers:" << endl;
    //list.printInfo();

    list.prepend(55);
    list.prepend(99);
    list.prepend(1);
    list.append(50);
    list.append(45);
    list.printInfo();
    /*
    //Print info then remove first element then print everything remaining
    cout << endl << "Print before popping the head value:" << endl;
    list.printInfo();
    list.deleteHead();
    cout << endl << "Print after deleting head value:" << endl;
    list.printInfo();

    //Print info then remove indexed element then print everything remaining
    cout<< endl << "Print before delete index value:" << endl;
    list.printInfo();
    list.deleteIndexedNode(2);
    cout<< endl << "Print after delete index value:" << endl;
    list.printInfo();

    //Print info then remove last element then print everything remaining
    cout<< endl << "Print before the tail deletion:" << endl;
    list.printInfo();
    list.lastPop();
    cout<< endl << "Print after pop:" << endl;
    list.printInfo();
    */

    //splitting the node list starts
    List** split_lists = list.splitList();

    //First half as per requirement
    cout<< endl << "Print sorted - first half:" << endl;
    List* listA = new List();
    listA->listCopy(split_lists[0]);
    listA->bubbleSort();
    listA->printInfo();

    //Second half as per requirement
    cout<< endl << "Print sorted - second half:" << endl;
    List* listB = new List();
    listB->listCopy(split_lists[1]);
    listB->bubbleSort();
    listB->printInfo();

    //Merge and prints the sorted info
    cout<< endl << "Print sorted - total:" << endl;
    List* listC = new List();
    listC->merge(listA, listB);
    listC->printInfo();

    return 0;
}
