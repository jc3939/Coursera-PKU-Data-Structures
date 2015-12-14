#include <iostream>
using namespace std;

class Node{
public:
   int element;
   Node* left;
   Node* right;
   Node(int value){
      element = value;
   }
};

int main(){
   //Node a, b, c;
   Node* a = new Node(10);
   Node* b = new Node(20);
   Node* c = new Node(30);

   a->left = b;
   a->right = c;

   Node list[3] = {*a, *b, *c};
   Node Temp = list[0];
   list[0] = list[2];
   list[2] = Temp;
   cout<<a->left->element<<endl;
   cout<<a->right->element<<endl;
   return 0;




}