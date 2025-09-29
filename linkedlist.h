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
		size = 0;
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
	  bool isItemAtEqual(int pos, T elem){
		if(pos>size){
			cout<<"Error, pos > size"<<endl;
			exit(1);
		}
		else{
			Node* temp = head;
			int tSize = pos-1;
			while(tSize>0){
				temp = temp->next;
				tSize--;
			}
			if(temp->data == elem){
				cout<<"Elems are equal at pos\n";
				return true;
			}
			else{
				cout<<"Elems are not equal at pos\n";
			}
			return false;
		}
	  }
	  void insertAt(int pos, T elem){
		if (pos>size){
			cout<<"Error, pos > size"<<endl;
			exit(1);
		}
		else if(pos ==1 ){
			head->data = elem;
			return;
		}
		else{
			Node* newNode = new Node;
			newNode -> data = elem;
			Node* temp  = head;
			int ts = pos - 1;
			while(ts>0){
				temp = temp->next;
				ts--;
			}
			newNode-> next = temp->next;
			temp-> next = newNode;
			size++;
			return;
		}
	  }
	  void insertEnd(T elem){
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
			size++;
			return;
		}
	  }
	  void removeAt(int pos){
		if (pos>size||pos<=0){
			cout<<"Error, pos > size"<<endl;
			exit(1);
		}
		else if (pos == 1){
			Node* temp = head;
			head = temp -> next;
			delete temp;
			size--;
		}
		else{
			int ts = pos - 1;
			Node* temp = head;
			Node* prev = temp;
			while(ts>0){
				prev = temp;
				temp = temp->next;
				ts--;
			}
			prev -> next = temp ->next;
			size--;
			delete temp;
	  }
	}
	  T retrieveAt(int pos){
			if (pos>size||pos<=0){
			cout<<"Error, pos > size"<<endl;
			exit(1);
		}
		else{
			int ts = pos - 1;
			Node* temp = head;
			while(ts>0){
				temp = temp->next;
				ts--;
			}
			return temp->data;
	  }
	}
	  void clearList(){
		Node* curr = head;
		Node* nextN = nullptr;
		while(curr!=nullptr){
			nextN = curr->next;
			delete curr;
			curr = nextN;
		}
		size = 0;
		head = nullptr;
	  }
	  void replaceAt(int pos, T elem){
			if (pos>size||pos<=0){
				cout<<"Error, pos > size"<<endl;
				exit(1);
			}
			else{
				int ts = pos - 1;
				Node* temp = head;
				while(ts>0){
					temp = temp->next;
					ts--;
				}
				temp->data = elem;
			}
			return;
	  }
	  ~linkedlist(){
		Node* curr = head;
		while(curr!=nullptr){
			Node* nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
		size = 0;
	  }
	linkedlist&  operator =(linkedlist& obj){
		if(this == &obj){
			return *this;
		}
		else{
			clearList(); //lowk need to review this
			Node* temp = obj.head;
			while(temp!=nullptr){
				insertEnd(temp->data);
				temp=temp->next;
			}
			return *this;
		}
	}
};