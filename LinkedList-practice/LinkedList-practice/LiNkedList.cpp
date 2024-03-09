#include<iostream>
using namespace std;


// double linked List

template<typename T>
class Node {
public:
	T data;
	Node<T>* Next;
	Node<T>* prev;
	Node(T d) : data(d), Next(NULL), prev(NULL) {}
};
template<typename T>
class doublelinkedlist {
public:
	Node<T>* head;
	doublelinkedlist() : head(nullptr) {}
	bool isEmpty() {
		if (!head) {
			return true;
		}
	}
	void insertNode(T d) {
		Node<T>* addNode = new Node<T>(d);
		addNode->Next = NULL;
		addNode->prev = NULL;
		if (head == nullptr) {
			head = addNode;

		}
		else {
			Node<T>* current = head;
			while (current->Next != nullptr) {

				current = current->Next;
			}
			current->Next = addNode;
			addNode->prev = current;
		}




	}
	Node<T>* insertAtFront(T d) {
		Node<T>* add = new Node<T>(d);

		if (head == nullptr) {
			head = add;

		}
		else {
			add->Next = head;

			head->prev = add;
			head = add;
		}
		return head;
	}
	Node<T>* insertAtindex(int index, T d) {
		Node<T>* curr = head;
		int x = 0;


		while (curr) {
			x++;
			curr = curr->Next;
		}

		if (index == 0) {
			return insertAtFront(d);

		}
		else if (index >= x) {
			cout << " Not Found Index :\n";
			return nullptr;
		}
		else {
			Node<T>* ADD = new Node<T>(d);
			
			Node<T>* current = head;
			int y = 0;
			while (y < index) {
				
				current = current->Next;
				y++;
			}
			ADD->prev = current->prev;
			current->prev->Next = ADD;
			ADD->Next = current;
			current->prev=ADD;

			
			return ADD;
		}
	}

	void Display() {
		Node<T>* current = head;
		while (current) {
			cout << current->data << " ";
			current = current->Next;
		}
		cout << endl;
		 current = head;
		while (current->Next) {
			current = current->Next;
		}
		while (current) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}

};

int main() {
	doublelinkedlist<int> s;    
	s.insertNode(3);
	s.insertNode(23);
	s.insertNode(34);
	s.insertNode(19);
	s.insertAtFront(78);
	s.insertAtindex(3, 99);
	s.Display();

}











//simple Linked List.....
//template<typename T>
//class Node {
//public:
//	T data;
//	Node<T>* Next;
//	Node(T d) : data(d), Next(NULL) {}
//};
//template<typename T>
//class simplelinkedlist {
//public:
//	Node<T>* head;
//	simplelinkedlist() : head(nullptr) {}
//	bool isEmpty() {
//		if (!head) {
//			return true;
//		}
//	}
//	void insertNode(T d) {
//		Node<T>* addNode = new Node<T>(d);
//		addNode->Next = NULL;
//		if (head == nullptr) {
//			head = addNode;
//			
//		}
//		else {
//			Node<T>* current = head;
//			while (current->Next != nullptr) {
//
//				current = current->Next;
//			}
//			current->Next = addNode;
//
//		}
//
//		
//		
//
//	}
//	Node<T>* insertAtFront(T d) {
//		Node<T>* add = new Node<T>(d);
//		
//		if (head == nullptr) {
//			head = add;
//			head->Next = nullptr;
//			
//		}
//		else {
//			add->Next = head;
//			
//			head = add;
//		}
//		return head;
//	}
//	Node<T>* insertAtindex(int index,T d) {
//		Node<T>* curr = head;
//		int x=0;
//
//		
//		while (curr) {
//			x++;
//			curr = curr->Next;
//		}
//		
//		if (index == 0) {
//			return insertAtFront(d);
//
//		}
//		else if (index>=x){
//			cout << " Not Found Index :\n";
//			return nullptr;
//		}
//		else {
//			Node<T>* ADD = new Node<T>(d);
//			Node<T>* prev = NULL;
//			Node<T>* current = head;
//			int y = 0;
//			while (y < index) {
//				prev = current;
//				current=current->Next;
//				y++;
//			}
//			
//			prev->Next = ADD;
//			ADD->Next = current;
//			return ADD;
//		}
//	}
//
//	void Display() {
//		Node<T>* current = head;
//		while (current) {
//			cout << current->data << " ";
//			current = current->Next;
//		}
//		cout << endl;
//	}
//
//};
//
//int main() {
//	simplelinkedlist<int> s;
//	s.insertNode(3);
//	s.insertNode(23);
//	s.insertNode(34);
//	s.insertNode(19);
//	s.insertAtFront(78);
//	s.insertAtindex(3, 99);
//	s.Display();
//
//}