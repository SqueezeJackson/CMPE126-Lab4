#include <iostream>
using namespace std;
#include "linkedlist.h"

int main(){
    linkedlist<int> list;
    list.insertEnd(5);
    list.insertEnd(4);
    list.insertEnd(3);
    list.insertEnd(2);
    list.insertEnd(1);
    cout<<"size: "<<list.listSize()<<endl;
    list.insertAt(2,9);
    list.removeAt(5);
    list.print();
    list.isItemAtEqual(3, 3);
    list.insertAt(1, 19);
    list.replaceAt(3, 13);
    list.print();
    list.clearList();
    list.print();
}