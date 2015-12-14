#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<typename T> class minHeap{
private:
    T heapArray[10000];
    int currentSize;
    int maxSize;
    
public:
    void BuildHeap();
    void siftDown(int i);
    void siftUp(int i);
    bool insert(T & node);
    bool remove();
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
bool minHeap<T>::insert(T & node){
    if(currentSize==100000){
        return false;
    }
    heapArray[currentSize]=node;
    currentSize++;
    return true;
}

template<typename T>
bool minHeap<T>::remove(){
    if(currentSize==0){
        return false;
    }
    cout<<heapArray[0]<<endl;
    heapArray[0]=heapArray[--currentSize];
    siftDown(0);
    return true;
}

template<typename T>
void minHeap<T>::siftDown(int position){
    int i = position;
    int j = 2*i+1;
    T temp = heapArray[i];
    while(j<currentSize){
        if(j<currentSize-1 && (heapArray[j]>heapArray[j+1])){
            j++;
        }
        if(temp>heapArray[j]){
            heapArray[i] = heapArray[j];
            i=j;
            j=2*j+1;
        }
        else break;
    }
    heapArray[i]=temp;
}

template<typename T>
void minHeap<T>::siftUp(int position){
    int i = position;
    int j = parent(i);
    T *temp = heapArray[i];
    while(j>=0){
        if(temp<heapArray[j]){
            heapArray[i] = heapArray[j];
            i=j;
            j=parent(j);
        }
        else break;
    }
    heapArray[i]=temp;
}


int main(){

    int t;
    int n;
    cin>>t;
    for(int i=0;i<t;i++){
        minHeap<int> *myHeap = new minHeap<int>();
        cin>>n;
        cin.ignore(10000, '\n');
        for(int j=0;j<n;j++){
            string str;
            int type, u;
            getline(cin, str);
            istringstream f(str);
            f>>type;
            if(type==2){
                //delete minimum node
                myHeap->remove();
                continue;
            }
            else if(type==1){
                f>>u;
                //insert u into heap
                myHeap->insert(u);
                myHeap->BuildHeap();
            }
        }
    }
    return 0;

}