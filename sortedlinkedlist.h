#include <iostream>

using namespace std;

template <typename T> class sortedlinkedlist{
	private:
	  struct Node{
		 T data;
		 struct Node* next = nullptr;
	  };
	  Node* head;
	  int size;
	public:
	  sortedlinkedlist(){
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
    sortedlinkedlist&  operator =(sortedlinkedlist& obj){
		if(this == &obj){
			return *this;
		}
		else{
			clearList();
			Node* temp = obj.head;
			while(temp!=nullptr){
				insertEnd(temp->data);
				temp=temp->next;
			}
			return *this;
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
      void insert(T elem){
        if(head==nullptr){
            Node* newNode = new Node;
            newNode->data = elem;
            newNode->next =nullptr;
            head = newNode;
            size++;
            return;
        }
        else if(elem <=head->data){
            Node* newNode = new Node;
            newNode ->data = elem;
            newNode -> next = head;
            head = newNode;
            size++;
            return;
        }
            Node* newNode = new Node;
            newNode -> data = elem;
            Node* temp = head->next;
            Node* prev = head;
            while(temp!=nullptr){
                if(elem>temp->data){
                    prev = temp;
                    temp = temp->next;
                    continue;
                }
                else if(elem<=temp->data){
                    newNode -> next = temp;
                    prev -> next = newNode;
                    size++;
                    return;
                }
            }
            temp -> next = newNode;
            newNode-> next = nullptr;
            size++;
            return;
      }
      void remove(T elem){
        Node* temp = head->next;
        Node* prev = head;
        if(head->data == elem){
            head = head-> next;
            delete prev;
            size--;
            return;
        }
      else{
        while(temp!=nullptr){
            if(elem<prev->data||(elem>prev->data&&elem<temp->data)){
                cout<<"element not in list";
                return;
            }
            else if(elem == temp->data){
                prev->next = temp -> next;
                delete temp;
                size--;
                return;
            }
            else if(elem>temp->data){
                prev =temp;
                temp = temp->next;
            }
        }
        cout<<"iterated through list and element was not found\n";
        return;
      }
      }
    };
