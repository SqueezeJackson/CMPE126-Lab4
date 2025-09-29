#include <iostream>

using namespace std;



template <typename T> class linkedlist{
	private:
	  struct Node{
		 T data;
		 struct Node* next
	  }
	  int size;
	public:
	  bool isEmpty();
	  bool isFull();
	  int listSize();
	  int maxListSize();
	  void print();
	  void insert(T elem);
	  void remove(T elem);
	  T retrieveAt(int pos);
	  void clearList();
	  ~linkedlist();
	 linkedlist&  operator =(linkedlist& obj);

}
