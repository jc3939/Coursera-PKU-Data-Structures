#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

template<typename T> class Node{
public:
    T indx;
    T coeff;
    Node<T> * next;

    Node(T _indx, T _coeff, Node<T> * nextValue=NULL){
        //cout<<"construct index"<<_indx<<endl;
        indx = _indx;
        coeff = _coeff;
        next = nextValue;
    }
};

template<typename T> class linkedList{

public:
    Node<T> *_pHead;
    Node<T> *_pTail;
    int len;
    linkedList(T heaIndx, T heaCoeff); //Constructors
    ~linkedList();
    void clear();
    bool isEmpty();
    int length();
    bool insert( int i,  T Indx, T Coeff);
    bool Sort();
    bool RemoveDup();
    bool append(T indx, T coeff);
    Node<T> *setPos(int p);
};

template<typename T>
linkedList<T>::linkedList(T heaIndx, T heaCoeff){
    _pHead = new Node<T>(heaIndx, heaCoeff);
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
bool linkedList<T>::append(T indx, T coeff){
    Node<T> *p = new Node<T>(indx, coeff);
    //cout<<"append index"<<p->indx<<endl;
    _pTail = p;
    int i = 0;
    Node<T> *pfinder = _pHead;
    while(i<len){
        pfinder=pfinder->next;
        i++;
    }
    pfinder->next = p;
    len++;
    return true;
}

//Sort linked list by indx in descending order.
template<typename T>
bool linkedList<T>::Sort(){
    Node<T> *p = _pHead->next;
    Node<T> *q;
    if (p == NULL){
        cout<<"Cannot sort an empty List!!!"<<endl;
        return false;
    }
    int tempIndex=0;
    int tempCoeff = 0; 
    while(p!=NULL){
        q = p->next;
        while(q!=NULL){
            if(q->indx>p->indx){
                //Swap indx and coeff values
                tempIndex = q->indx;
                q->indx = p->indx;
                p->indx = tempIndex;
                tempCoeff = q->coeff;
                q->coeff = p->coeff;
                p->coeff=tempCoeff;
            }
            q = q->next;
        }
        p=p->next;
    }
    return true;
}

template<typename T>
bool linkedList<T>::RemoveDup(){
    Node<T> *p = _pHead->next;
    
    if(p==NULL){
        cout<<"Cannot operate an empty List!!!"<<endl;
        return false;
    }
    Node<T> *q = p->next;
    while(p!=NULL && q!=NULL){
        while(p->indx==q->indx){
            p->coeff+=q->coeff;
            q = q->next;
            if(q==NULL){
                p->next=NULL;
                return true;
            }
            if(p->indx!=q->indx){
                p->next = q;
                break;
            }
        }
        p = p->next;
        if(p==NULL) return true;
        q = p->next;
    }
    return true;
}


int main(){
    ifstream infile("/Users/jianjun_chen/Documents/Coursera-PKU-Data-Structures/input.txt");
    int coeff, indx;
    int n;
    string line;

    getline(infile, line);
    stringstream linestream(line);

    linestream>>n;
    cout<<n<<"&&&&"<<endl;
    while(n!=0){
        //construct new linked list array1 and array2 with
        //-1 as header and -2 as tail.
        linkedList<int> *array1 = new linkedList<int>(-1, 0);
        linkedList<int> *array2 = new linkedList<int>(-1, 0);
        getline(infile, line);
        stringstream linestream1(line);
        //cout<<line<<endl;
        //linestream>>coeff>>indx;
        
        while(linestream1>>coeff>>indx){
            cout<<coeff<<" "<<indx<<endl;
            if(indx<0){
                break;//as each line will end with an negative index
            }
            array1->append(indx, coeff);
        }
        getline(infile, line);
        stringstream linestream2(line);

        while(linestream2>>coeff>>indx){
            if(indx<0){
                break;
            }
            array2->append(indx, coeff);
        }

        //sort each linked list large to small by their index.
        array1->Sort();
        array2->Sort();
        //merge nodes with same index.
        array1->RemoveDup();
        array2->RemoveDup();

        //Start from the first node of linked lists.
        Node<int> *p1 = array1->_pHead->next;
        Node<int> *p2 = array2->_pHead->next;


        Node<int> *p1a = array1->_pHead;//p1a to store previous node of p1
        Node<int> *p1r;
        Node<int> *p2r;
        while(p1!=NULL || p2!=NULL){
            //p1r and p2r store next node of p1, p2.
            if(p1==NULL){
                p1a->next=p2;
                //cout<<"Now p1a->next->indx is "<<p1a->next->indx<<endl;
                break;
            } else if(p2==NULL){
                break;
            }
            p1r = p1->next;
            p2r = p2->next;
            if(p1->indx==p2->indx){
                //if p1 has same index with p2, then p1.index+p2.index
                //delete p2.
                p1->coeff+=p2->coeff;
                p1a = p1;
                p1 = p1r;
                p2 = p2r;
            }else if(p1->indx < p2->indx){
                //if p1.index>p2.index, then insert p2 into 
                //p1 and p1.next(p1r)
                p1a->next = p2;
                p2->next = p1;
                p1a = p2;
                p2 = p2r;
            }else{
                //if p1.index<p2.index, then insert p2 into 
                //p1 and p1's previous node.
                p1a = p1;
                p1 = p1->next;              
            }
        }
        p1 = array1->_pHead->next;
        while(p1!=NULL){
            //cout<<p1->coeff<<" "<<p1->indx<<endl;
            if(p1->coeff!=0){
                cout << "[ "<<p1->coeff<<" "<<p1->indx<<" ] ";
            }
            p1 = p1->next;
        }
        cout << endl;
        n--;
    }
}