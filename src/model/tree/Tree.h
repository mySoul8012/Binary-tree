//
// Created by ming on 18-12-9.
//

#ifndef UNTITLED4_TREE_H
#include "BitNode.h"
#include <stack>
#include <stdexcept>
#include <semaphore.h>
#include <exception>
#include <queue>    // 队列

#define UNTITLED4_TREE_H

// 定义新的异常
struct sem_exception:public std::exception{
    // 重写what
    const char* what() const throw(){
        return "入栈出现错误";
    }
};
// 定义树
template <class T>
class Tree {
private:
    // 树的深度
    int depth = 0;
    // 创建树时输入值
    std::string createString = "";
    void recursion(BitNode<char>* tree); // 输出方法
    void recursionBefore(BitNode<char>* tree);
    void recursionCenter(BitNode<char>* tree);
    void recursionAfter(BitNode<char>* tree);
    void recursionBeforer(BitNode<char>* tree);
    BitNode<char>* Find(BitNode<char>* tree, char x);
    int get(BitNode<char>* tree);
    int count(BitNode<char>* tree);
public:
    BitNode<char>* bitNodeTop = nullptr;
    // 获取树中叶子节点数量
    int CountLeaf();
    // 获取二叉树深度
    int GetTreeDepth();
    // 结果
    std::string resuful = "";
    // 构造
    Tree(); // 默认构造
    Tree(std::string& _str);    // 根据输入值创建
    // 输出二叉树
    void DispBiTNode();
    // 先序遍历二叉树
    void PreOrderTraverse();
    // 中序遍历二叉树
    void InOrderTraverse();
    // 后序遍历二叉树
    void PostOrderTraverse();
    // 层次遍历二叉树
    void LeveLOrder();
    // 查找二叉树中指定的节点
    BitNode<char>* findNode(char x);
    // get和set方法
    int getDepth(){
        return this->depth;
    }
    void setDepth(int _depth){
        this->depth = _depth;
    }
    BitNode<char>* getBitNodeTop(){
        return this->bitNodeTop;
    }
    void setBitNodeTop(BitNode<T>* _bitNodeTop){
        this->bitNodeTop = _bitNodeTop;
    };
    std::string getCreateString(){
        return this->createString;
    }
    void setCreateString(std::string _createString){
        this->createString = _createString;
    }
};

// 构造函数
// 默认创建树，默认创建深度为1，仅有头节点的树
template <class T>
Tree<T>::Tree() {
    // 深度
    this->setDepth(1);
    // 头节点
    auto* bitNode = new BitNode<char>('A');
    this->bitNodeTop = bitNode;
    // 创建树的输入
    std::string tmpString = "A(,)";
    this->setCreateString(tmpString);
}
// 有参数的创建,输入字符串
template <class T>
Tree<T>::Tree(std::string& _str) {
    try {
        if (_str.length() == 0)
            throw std::invalid_argument("字符串无效");
    }catch(std::invalid_argument& e){
        Tree<T>();
        return;
    }

    // 定义符号栈
    std::stack<char> symbolStack;
    // 定义节点栈
    std::stack<BitNode<char>*> nodeStack;
    // 定义左右节点，sem
    int sem = 0;

    // 对头节点处理
    auto* tmpBitNode = new BitNode<char>(_str[0]);
    nodeStack.push(tmpBitNode);
    this->bitNodeTop = tmpBitNode;
    // 深度
    this->setDepth(1);
    // 储存输入值
    this->setCreateString(_str);
    /* 以下是debug时
    char a = _str[1];
    symbolStack.push(_str[1]);
    sem = 0;
    a = _str[2];
    nodeStack.top()->setLchild(new BitNode<char>(_str[2]));
    a = _str[3];
    sem = 1;
    a = _str[4];
    nodeStack.top()->setRchild(new BitNode<char>(_str[4]));
    a = _str[5];
    symbolStack.pop();
    nodeStack.pop();
    this->depth++;
    a = _str.length();
     */
    /*
        调试
     */
    // 第二次测试
    // 1
    /*
    symbolStack.push(_str[1]);
    // 入节点栈
    nodeStack.push(tmpBitNode);
    // 进行原子信号量操作
    sem = 0;
    // 2
    // 证明为左子树
    tmpBitNode = new BitNode<char>(_str[2]);
    // 设置子节点
    nodeStack.top()->setLchild(tmpBitNode);
    // 3
    // 入栈
    symbolStack.push(_str[3]);
    // 入节点栈
    nodeStack.push(tmpBitNode);
    // 进行原子信号量操作
    sem = 0;
    // 4
    // 入栈
    // 证明为左子树
    tmpBitNode = new BitNode<char>(_str[4]);
    // 设置子节点
    nodeStack.top()->setLchild(tmpBitNode);
    // 5
    // 入栈
    symbolStack.push(_str[5]);
    // 入节点栈
    nodeStack.push(tmpBitNode);
    // 进行原子信号量操作
    sem = 0;
    // 6
    tmpBitNode = new BitNode<char>(_str[6]);
    // 设置子节点
    nodeStack.top()->setLchild(tmpBitNode);
    // 7
    sem = 1;
    // 8
    // 证明为右子树
    tmpBitNode = new BitNode<char>(_str[8]);
    // 设置子节点
    nodeStack.top()->setRchild(tmpBitNode);
    // 9
    symbolStack.pop();
    // 父节点出栈
    nodeStack.pop();
    sem = 0;
    this->depth++;
    // 10
    sem = 1;
    // 出栈
    nodeStack.pop();
    // 11
    tmpBitNode = new BitNode<char>(_str[11]);
    // 设置子节点
    nodeStack.top()->setRchild(tmpBitNode);
    // 入栈
    nodeStack.push(tmpBitNode);
    // 12
    symbolStack.push(_str[12]);
    // 进行原子信号量操作
    sem = 0;
    // 13
    tmpBitNode = new BitNode<char>(_str[13]);
    // 设置子节点
    nodeStack.top()->setLchild(tmpBitNode);
    // 入栈
    nodeStack.push(tmpBitNode);
    // 14
    sem = 1;
    // 出栈
    nodeStack.pop();
    // 15
    symbolStack.pop();
    // 父节点出栈
    nodeStack.pop();
    sem = 0;
    // 16
    symbolStack.pop();
    // 父节点出栈
    nodeStack.pop();
    sem = 0;
*/
    for(int i = 1; i < _str.length(); i++){
        switch(_str[i]){
            case '(':
                // 入栈
                symbolStack.push(_str[i]);
                // 入节点栈
                nodeStack.push(tmpBitNode);
                // 进行原子信号量操作
                sem = 0;
                break;
            case ',':
                // 即将进入右子树
                sem = 1;
                break;
            case ')':
                // 即将完成一层级的遍历
                // 出栈
                symbolStack.pop();
                // 父节点出栈
                nodeStack.pop();
                sem = 0;
                this->depth++;
                break;
            default:
                // 对其余情况进行处理
                if(sem == 0){
                    // 证明为左子树
                    tmpBitNode = new BitNode<char>(_str[i]);
                    // 设置子节点
                    nodeStack.top()->setLchild(tmpBitNode);
                }
                if(sem == 1){
                    // 证明为右子树
                    tmpBitNode = new BitNode<char>(_str[i]);
                    // 设置子节点
                    nodeStack.top()->setRchild(tmpBitNode);
                }
                break;
        }
    }
}
// 输出二叉树 带括号
template<class T>
void Tree<T>::DispBiTNode() {

    // 临时保存结果
    //std::string restful;
   // auto a = this->getBitNodeTop();
    // 递归调用
    this->recursion(this->getBitNodeTop());
    //restful = "2344444444";
    //this->resuful = restful;
}


// 先序遍历二叉树
template<class T>
void Tree<T>::PreOrderTraverse() {

    // 递归调用
    recursionBefore(this->getBitNodeTop());
}

// 中序遍历二叉树
template<class T>
void Tree<T>::InOrderTraverse() {
    // 递归调用
    recursionCenter(this->getBitNodeTop());
}

// 先序递归
template<class T>
void Tree<T>::recursionBefore(BitNode<char> *tree) {
    if (tree != nullptr)
    {
        this->resuful += tree->getData();
            this->recursionBefore(tree->getLchild());
            this->recursionBefore(tree ->getRchild());
    }

    }


// 输出递归函数
template<class T>
void Tree<T>::recursion(BitNode<char>* tree){
    if (tree != nullptr)
    {
        this->resuful += tree->getData();
        if (tree->getLchild() != nullptr || tree->getRchild() != nullptr)
        {
            this->resuful += "(";
            this->recursion(tree->getLchild());
            this->resuful += ",";
            this->recursion(tree ->getRchild());
            this->resuful += ")";
        }
    }
}

// 中序
template<class T>
void Tree<T>::recursionCenter(BitNode<char>* tree){
    if (tree != nullptr)
    {
            this->recursionCenter(tree->getLchild());
            this->resuful += tree->getData();
            this->recursionCenter(tree ->getRchild());
    }
}

template<class T>
void Tree<T>::recursionAfter(BitNode<char> *tree) {
    this->resuful += "\n";
    if (tree != nullptr)
    {
        this->resuful += tree->getData();
        if (tree->getLchild() != nullptr || tree->getRchild() != nullptr)
        {
            this->resuful += "(";
            this->recursion(tree->getLchild());
            this->resuful += ",";
            this->recursion(tree ->getRchild());
            this->resuful += ")";
        }
    }
}

template<class T>
void Tree<T>::PostOrderTraverse() {
    this->recursionBeforer(this->getBitNodeTop());
}

template<class T>
void Tree<T>::recursionBeforer(BitNode<char> *tree) {
    if (tree != nullptr)
    {
        this->recursionBeforer(tree->getLchild());
        this->recursionBeforer(tree ->getRchild());
        this->resuful += tree->getData();
    }
}

// 层次遍历二叉树
template<class T>
void Tree<T>::LeveLOrder() {
    // 定义队列
    std::queue<BitNode<char>*> queue;
    // 跟节点入队
    queue.push(this->bitNodeTop);
    // 进行循环
    while(!queue.empty()){    // 当队列为非空，进行循环，遍历操作
        // 输出结果
        this->resuful += queue.front()->getData();
        // 左右节点非空入栈
        if (queue.front()->getLchild()){
            queue.push(queue.front()->getLchild());
        }
        if (queue.front()->getRchild()){
            queue.push(queue.front()->getRchild());
        }
        // 头元素出栈
        queue.pop();
    }

}


// 查找二叉树中的某个节点
template<class T>
BitNode<char> *Tree<T>::findNode(char x) {
    return Find(this->bitNodeTop, x);
}

template<class T>
BitNode<char> *Tree<T>::Find(BitNode<char> *tree, char x) {
    BitNode<char>*p = nullptr;
    if(tree != nullptr){
        if(tree->getData() == x){
            return tree;
        }

        // 下一个节点
        p = Find(tree->getLchild(), x);
        if(p != nullptr){
            return p;
        }

        // 寻找右节点
        p = Find(tree->getRchild(),x);
        if(p != nullptr) {
            return p;
        }
    }
    // 全部为找到
    return nullptr;
}

// 获取节点深度
template<class T>
int Tree<T>::GetTreeDepth() {
    return get(this->bitNodeTop);
}

template<class T>
int Tree<T>::get(BitNode<char> *tree) {
    int left, right;
    if(tree != nullptr){
        return 0;
    }

    left = get(tree->getLchild())+1;    // 当前遍历到的节点数目+1
    right = get(tree->getRchild())+1;
    if(left > right){
        return left;
    }
    return right;
}

template<class T>
int Tree<T>::count(BitNode<char> *tree) {
    if(tree->getRchild() == nullptr && tree->getLchild() == nullptr){
        return 1;
    }
    return count(tree->getLchild()) + count(tree->getRchild());
}

template<class T>
int Tree<T>::CountLeaf() {
    return count(bitNodeTop);
};
/*
template<class T>
std::string Tree<T>::recursionBefore(BitNode<char>* tree){
    std::string result = "";
    if(tree != nullptr){
        // 中间节点
        result += tree->getData();
        // 递归调用二叉树左节点
        result += recursionBefore(tree->getLchild());
        // 递归调用二叉树右节点
        result += recursionBefore(tree->getRchild());
    }
    return result;
}
 */
//
#endif //UNTITLED4_TREE_H
