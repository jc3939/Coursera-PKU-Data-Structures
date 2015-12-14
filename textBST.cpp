#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<typename T> class Node{
public:
    T data;
    int level;
    Node<T> * left;
    Node<T> * right;
    Node(T value, int _level){
        data = value;
        level = _level;
    }
};

template<typename T> class BST{
private:
    Node<T> * root;
public:
    void preOrder(Node<T> *root);
    void inOrder(Node<T> *root);
    void postOrder(Node<T> *root);
    BST(){root = NULL;}
    bool insertNode(Node<T> *root, Node<T> *node);
    Node<T> * getRoot(){return root;}
};

template<typename T> 
void BST<T>::preOrder(Node<T> *root){
    if(root==NULL||root->data=='*') return;
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}

template<typename T> 
void BST<T>::postOrder(Node<T> *root){
    if(root==NULL||root->data=='*') return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
}

template<typename T> 
void BST<T>::inOrder(Node<T> *root){
    if(root==NULL||root->data=='*') return;
    inOrder(root->left);
    cout<<root->data;
    inOrder(root->right);
}

template<typename T> 
bool BST<T>::insertNode(Node<T> * root, Node<T> *node){
    while(node->level-2 >= root->level){
        if(root->right == NULL){
            root = root->left;
        } else {
            root = root->right;
        }
    }
    if(root->left==NULL){
        root->left = node;
    }else{
        root->right = node;
    }
    return true;
}


int main(){
    int n;
    cin>>n;
    cin.ignore(10000, '\n');
    for(int i=0;i<n;i++){
        string s;
        Node<char> *root;
        BST<char> * BinaryTree = new BST<char>();
        while(getline(cin, s)){
            istringstream f(s);
            char c;
            int level = 0;
            if(s=="0"){
                BinaryTree->preOrder(root);
                cout<<endl;
                BinaryTree->postOrder(root);
                cout<<endl;
                BinaryTree->inOrder(root);
                cout<<endl;
                cout<<endl;
                break; 
            }
            while(f>>c){
                if(c=='-'){
                    level++;
                    continue;
                }
                if(c=='*'){
                    Node<char> *starNode = new Node<char>(c, level);
                    BinaryTree->insertNode(root, starNode);
                    continue;
                }
                if(isalpha(c)){
                    if(level==0){
                        root = new Node<char>(c, 0);
                    }else{
                        Node<char> *datanode = new Node<char>(c, level);
                        BinaryTree->insertNode(root, datanode);
                    }
                    continue;
                }
            }
        }
    }


}