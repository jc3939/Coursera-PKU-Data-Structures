#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T> class Node{
public:
    T element;
    Node<T> * left;
    Node<T> * right;
    Node<T> * parent;
};

template<typename T> class minHeap{
private:
    Node<T> heapArray[10000];
    int currentSize;
    int maxSize;
    
public:
    void BuildHeap();
    void siftDown(int i);
    void siftUp(int i);
    bool insert(Node<T>* node);
    bool remove(Node<T>& p);
    int parent(int pos);
};

template<typename T>
int minHeap<T>::parent(int pos){
    if(pos==0){
        return 0;
    }
    return (pos-1)/2;
}

template<typename T>
void minHeap<T>::BuildHeap(){
    if(currentSize<=1){
        return;
    }
    for(int i=currentSize/2-1;i>=0;i--){
        siftDown(i);
    }
}

template<typename T>
bool minHeap<T>::insert(Node<T>* node){
    if(currentSize==100000){
        return false;
    }
    heapArray[currentSize]=*node;
    currentSize++;
    BuildHeap();
    return true;
}

template<typename T>
void minHeap<T>::siftDown(int position){
    int i = position;
    int j = 2*i+1;
    Node<T> temp = heapArray[i];
    while(j<currentSize){
        if(j<currentSize-1 && (heapArray[j].element > heapArray[j+1].element)){
            j++;
        }
        if(temp.element>heapArray[j].element){
            heapArray[i] = heapArray[j];
            i=j;
            j=2*j+1;
        }
        else break;
    }
    heapArray[i]=temp;
}

template<typename T>
bool minHeap<T>::remove(Node<T> &p){
    if(currentSize==0) return false;
    p = heapArray[0];
    heapArray[0]=heapArray[--currentSize];
    siftDown(0);
    return true;
}

template <class T> class HuffmanTree{
private:
    void MergeTree(Node<T>& ht1, Node<T>& ht2, Node<T> *parent);
public:
    Node<T>* root;
    HuffmanTree(T weight[],int n);
    int traverse(Node<T>* p, int depth);
};

template<class T>
HuffmanTree<T>::HuffmanTree(T weight[], int n) {
    minHeap<T> *heap = new minHeap<T>();
    Node<T>* parent;
    Node<T> leftchild;
    Node<T> rightchild;
    Node<T> * NodeList = new Node<T>[n];

    for(int i=0; i<n; i++) {
        NodeList[i].element =weight[i];
        heap->insert(&NodeList[i]);
    }

    for(int i=0;i<n-1;i++) { 
        parent = new Node<T>;
        heap->remove(leftchild);
        heap->remove(rightchild);
        MergeTree(leftchild,rightchild,parent);
        heap->insert(parent);
        root=parent;
    }
    delete []NodeList;
}

template<class T>
void HuffmanTree<T>::MergeTree(Node<T>& ht1, Node<T>& ht2, Node<T> * parent){
     parent->element = ht1.element + ht2.element;
     parent->left = &ht1;
     parent->right = &ht2;
     return;
};

template<class T>
int traverse(Node<T> *p, int depth){
    int sum = 0;
    int child = 0;
    cout<<p->element<<" "<<depth<<endl;
    cout<<p->element<<" "<<depth<<endl;
    cout<<p->right->element<<"****"<<depth<<endl;
    // cout<<p->right<<"****"<<depth<<endl;
    // cout<<p->left->element<<"****"<<depth<<endl;
    // cout<<p->left<<"****"<<depth<<endl;
    if(p->right!=NULL){
        cout<<p->right->element<<"+++"<<depth<<endl;
        sum += traverse(p->right, depth+1);
        child++;
    }
    if(p->left!=NULL){
        cout<<p->left->element<<"***"<<depth<<endl;
        cout<<p->left<<"***"<<depth<<endl;
        sum += traverse(p->left, depth+1);
        child++;
    }

    if(!child){
        cout<<p->element<<endl;
        sum = p->element*depth;
    }
    return sum;
}

int main(){
    int huffman[10000] = {0};

    int n;

    cin>>n;
    int num;
    int result;
    for(int i=0;i<n;i++){
        cin>>huffman[i];
    }

    HuffmanTree<int> *huffmanT = new HuffmanTree<int>(huffman, n);

    cout<<traverse(huffmanT->root, 0)<<endl;
    return 0;
}