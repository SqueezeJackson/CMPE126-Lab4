#include <iostream>
using namespace std;
#include "linkedlist.h"
#include "sortedlinkedlist.h"

int main(){
    // linkedlist<int> list;
    // list.insertEnd(5);
    // list.insertEnd(4);
    // list.insertEnd(3);
    // list.insertEnd(2);
    // list.insertEnd(1);
    // cout<<"size: "<<list.listSize()<<endl;
    // list.insertAt(2,9);
    // list.removeAt(5);
    // list.print();
    // list.isItemAtEqual(3, 3);
    // list.insertAt(1, 19);
    // list.replaceAt(3, 13);
    // list.print();
    // list.clearList();
    // list.print();
    // cout<<"size: "<<list.listSize()<<endl;
    // cout<<"3rd element is (getting with retrreve func)\nShould give an error since list was cleared\n";
    // cout<<list.retrieveAt(3)<<endl;
    sortedlinkedlist<int> sl;
     sl.insert(5);
     sl.insert(4);
     sl.insert(3);
     sl.insert(2);
     sl.insert(1);
     sl.print();
     cout<<endl;
     sl.remove(2);
     sl.remove(3);
     sl.print();
    return 0;
}