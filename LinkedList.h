#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template <class T>
class Node{

	public:
		T data;  // 입력받은 값을 저장할 변수
		Node *link;  // 다음에 이어지는 노드를 가리키는 포인터

		Node(T element){

			data = element;
			link = 0;

		}

	};

//LinkedList Class
template <class T>
class LinkedList{

	protected:
		Node<T> *first;  // 제일 앞에 위치한 노드를 가르키는 포인터
		int current_size;
	
	public:
		LinkedList(){  // 생성자

			first = 0;
			current_size = 0;

		};

		int GetSize(){  // 연결 리스트에 있는 노드들의 개수 출력

			return current_size;

		};

		void Insert(T element);  // 제일 앞에 입력받은 데이터를 포함하는 노드 삽입
		
		virtual bool Delete(T &element);  // 연결 리스트의 제일 끝에 위치한 노드 삭제

		void Print();  // 연결 리스트의 전체 데이터를 순차적으로 출력

};


template <class T>
void LinkedList<T>::Insert(T element){  // 제일 앞에 입력받은 데이터를 포함하는 노드 삽입

	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;  // 입력받은 데이터를 저장하는 노드 다음으로, 기존의 연결 리스트의 제일 첫 부분에 위치한 노드를 연결
	first = newnode;  // 이후 제일 첫 부분에 삽입한 노드가 있음을 저장
	current_size++;  // 연결 리스트에 위치한 노드들의 개수에 +1

}

template <class T>
bool LinkedList<T>::Delete(T &element){  // 연결 리스트의 제일 끝에 위치한 데이터를 삭제

	if (first == 0) return false;
	
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	while(1){
		
		if (current->link == 0){  // 제일 끝 노드는 뒤에 이어지는 노드가 없음을 이용해서, 연결리스트의 가장 끝 노드로 이동
			
			if (previous) {  // 제일 끝 노드의 앞에 연결된 노드가 있으면
			
				previous->link = current->link;  // 해당 노드를 연결리스트의 끝 부분으로 설정
			
			}
			else {
				
				first = first->link; 
			
			}
			break;
		
		}
		
		previous = current;
		current = current -> link;
	
	}

	element = current -> data;
	delete current;
	current_size--;

	return true;

}

template <class T>
void LinkedList<T>::Print(){  // 리스트의 원소들을 순서대로 출력하는 함수

	Node<T> *i;
	int index = 1;

	if (current_size != 0){

		for( i = first; i != NULL; i=i->link){

			if (index == current_size){

				cout << "[" << index << "|";
				cout << i -> data <<"]";

			}
			
			else {

				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;

			}

		}

		cout << endl;

	}

}

#endif
