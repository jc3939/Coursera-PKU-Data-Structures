#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T> class Node{
public:
    T data;
    Node<T> * left;
    Node<T> * right;

    Node(T info, Node<T> * leftValue=NULL, Node<T> * rightValue=NULL){
        data = info;
        left = leftValue;
        right = rightValue;
    }
};

Node<int>* findRoot(int * inorder, int * aftorder, int length){
    if(length==0){
        return NULL;
    }
    Node<int>* node = new Node<int>(*(aftorder+length-1));
    cout<<node->data<<" ";
    int rootIndex = 0;
    for(;rootIndex<length;rootIndex++){
        if(*(inorder+rootIndex)==*(aftorder+length-1)){
            break;
        }
    }
    node->left = findRoot(inorder, aftorder, rootIndex);
    node->right = findRoot(inorder+rootIndex+1, aftorder + rootIndex , length - (rootIndex + 1));
    return node;
    
}

int main(){
    int midtraverse[65536];
    int postraverse[65536];

    int nodeNum = 0;
    while(cin>>midtraverse[nodeNum++]){
        //cout << midtraverse[0]<<endl;
        if(cin.get()!=' '){
            break;
        }
    }

    nodeNum = 0;
    while(cin>>postraverse[nodeNum++]){
        //cout << postraverse[0]<<endl;
        if(cin.get()!=' '){
            //cout<<"*******"<<nodeNum<<endl;
            break;
        }
    }
    //cout<<nodeNum<<endl;

    findRoot(midtraverse, postraverse, nodeNum);
    cout<<endl;
    return 0;

}