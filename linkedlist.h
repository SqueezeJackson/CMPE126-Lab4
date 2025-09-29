#include <iostream>

using namespace std;

template <typename T> class linkedlist{
	private:
	  struct Node{
		 T data;
		 struct Node* next = nullptr;
	  };
	  Node* head;
	  int size;
	public:
	  linkedlist(){
		int size = 0;
		head = nullptr;
	  }
	  bool isEmpty(){
		if(size == 0){
			return true;
		}
		return false;
	  }
	  bool isFull(){
		if(size == 0){
			return false;
		}
		return true;
	  }
	  int listSize(){
		return size;
	  }
	  int maxListSize(){
		return size;
	  }
	  void print(){
		Node* temp = head;
		while(temp!=nullptr){
			cout<<temp->data<<endl;
			temp = temp->next;
		}
		return;
	  }
	  void insert(T elem){
		Node* newNode = new Node;
		newNode -> data = elem;
		newNode -> next = nullptr;
		if(head == nullptr){
			head = newNode;
			size++;
			return;
		}
		else{
			//  cout<<"this is getting hit\n";
			Node* temp = head;
			while(temp->next!=nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
			i++;
			return;
		}
	  }
	  void remove(T elem);
	  T retrieveAt(int pos);
	  void clearList();
	  ~linkedlist(){
		Node* curr = head;
		while(curr!=nullptr){
			Node* nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
	  }
	 //linkedlist&  operator =(linkedlist& obj);
};

