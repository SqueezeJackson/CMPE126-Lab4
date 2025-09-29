#include <iostream>
using namespace std;
#include "linkedlist.h"

int main(){
    linkedlist<int> list;
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    list.print();
}