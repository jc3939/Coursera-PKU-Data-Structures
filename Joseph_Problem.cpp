#include <iostream>
using namespace std;

template<typename T> class Node{
public:
	T data;
	Node<T> * next;

	Node(T info, Node<T> * nextValue=NULL){
		data = info;
		next = nextValue;
	}
};

template<typename T> class linkedList{

public:
	Node<T> *_pHead;
	Node<T> *_pTail;
	int len;
	linkedList(T heaData, T taiData); //Constructors
	~linkedList();
	void clear();
	bool isEmpty();
	int length();
	bool insert( int i,  T value);
	bool del(const int i);
	Node<T> *setPos(const int p);
};

template<typename T>
linkedList<T>::linkedList(T heaData, T taiData){
	_pHead = new Node<T>(heaData);
	_pTail = new Node<T>(taiData);
	_pTail->next = _pHead;
	_pHead->next = _pTail;
	len=0;
}

template<typename T>
bool linkedList<T>::isEmpty(){
	if (len == 0) {
		return true;
	} else return false;
}

template<typename T>
int linkedList<T>::length(){
	return len;
}

template<typename T>
Node<T> * linkedList<T>::setPos(int i){
	int count = 0;
	if(i==-1)
		return _pHead;
	Node<T> *p = _pHead->next;
	while (p!=NULL && count < i){
		p = p->next;
		count++;
	}
	return p;
}

template<typename T>
bool linkedList<T>::insert(int i, T value){
	if(isEmpty()){
		Node<T> *q = new Node<T>(value);
		_pHead->next = q;
		_pTail = q;
		q->next = _pHead;
		len++;
		return true;
	}
	Node<T> *p;
	p = setPos(i-1);
	if (p==NULL) {
		cout<<"Illegal insert!"<<endl;
		return false;
	}
	Node<T> *q = new Node<T>(value);
	p->next = q;
	if(p==_pTail){
		_pTail=q;
		_pTail->next = _pHead;
		//cout<<"now tail number is "<<q->data<<endl;
	}
	len++;
	return true;
}

template<typename T>
bool linkedList<T>::del(const int i){
	Node<T> *p = setPos(i);
	if (p==NULL) {
		cout << i<<endl;
		cout<<"Illegal deletion!"<<endl;
		return false;
	}
	Node<T> *prev = setPos(i-1);
	prev->next = p->next;
	if(p==_pTail){
		_pTail=prev;
	}
	len--;
	return true;
}

int main(){
	int n, m;
	linkedList<int> *aList = new linkedList<int>(-1, -2);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		aList->insert(i, i+1);
	}
	/*
	Node<int> *p = aList->_pHead->next;
	for(int i=0;i<n;i++){
		cout<<p->data<<" ";
		p = p->next;
	}*/

	int count = n;
	int i=0;
	Node<int> *ptr;
	ptr = aList->_pHead->next;
	while(count != 1){
		i++;
		//cout<<"now it is "<<ptr->data<<endl;
		if((i+1)%m==0){
			if(ptr->next==aList->_pHead){
				//cout<<"first num: "<<aList->_pHead->next->data<<" delete: "<< aList->_pHead->next->data<<endl;
				aList->_pHead->next=aList->_pHead->next->next;
			}
			else{
				//cout<<"first num: "<<aList->_pHead->next->data<<" delete: "<< ptr->next->data<<endl;
				ptr->next = ptr->next->next;
			}
			count--;
			i=0;
		}
		//cout << i <<" "<<ptr->next->data<<endl;
		if(ptr->next == aList->_pHead){
			ptr=ptr->next->next;
		}
		else{
			ptr = ptr->next;
		}
	}
	cout<<aList->_pHead->next->data<<endl;
	return 0;
}