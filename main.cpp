
#include <iostream>
#include "Tree.h"
using namespace std;


int main() {
    auto bitNode = new BitNode<std::string>("4") ;
    std::cout << bitNode->getData() << std::endl;

    std::string string = "A(B(D(H,I),E(J,)),C(F,G))";
    std::cout << string << std::endl;
    auto tree = new Tree<std::string>(string);
    cout << tree->getDepth() << endl;
    cout << tree ->getBitNodeTop()->getData() << endl;
    cout << tree ->getCreateString() << endl;
    cout << 333 << endl;
    tree ->DispBiTNode();

    cout << tree ->resuful<< endl;
    cout << 1111 << endl;
    tree->resuful = "";
    tree->PreOrderTraverse();
    cout << tree->resuful << endl;
    //cout << tree ->PreOrderTraverse() << endl;
    cout << 2222 << endl;
    tree->resuful = "";
    tree ->InOrderTraverse() ;
    cout << tree->resuful << endl;
    tree->resuful = "";
    tree ->PostOrderTraverse();
    cout << tree->resuful << endl;
//    cout << tree  ->PostOrderTraverse() << endl;
//    bitnode.setData("3");
   // bitnode = new BitNode<std::string>();
    //cout << bitnode.getData() << endl;
 //   Tree<int>* tree;
 //   cout <<  tree->getBitNodeTop()->getData() << endl;
    return 0;
}