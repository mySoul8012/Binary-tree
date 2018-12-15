//
// Created by ming on 18-12-9.
//
#ifndef UNTITLED4_BITNODE_H
#include <cstddef>
#include <string>
#define UNTITLED4_BITNODE_H

// 节点
template<class T>
class BitNode {
private:

    BitNode<T>* lchild;    // 指向左节点
    BitNode<T>* rchild;    // 指向右节点
public:
    T data;
    BitNode();
    BitNode(T _data);

    // 数据域
    void setData(T _data);
    T getData();
    // 左节点
    void setLchild(BitNode*_lchild);
    BitNode<T>* getLchild();
    // 右节点
    void setRchild(BitNode* _rchild);
    BitNode<T> *getRchild();
};

// 构造函数
template <class T>
BitNode<T>::BitNode(){
    this->data = NULL;
    this->rchild = NULL;
    this->rchild = NULL;
}

template <class T>
BitNode<T>::BitNode(T _data) {
    this->data = _data;
    this->rchild = NULL;
    this->lchild = NULL;

}


// 数据域
template <class T>
T BitNode<T>::getData() {
    return this->data;
};

template <class T>
void BitNode<T>::setData(T _data) {
    this->data = _data;
}

// 左节点
template <class T>
void BitNode<T>::setLchild(BitNode* _lchild) {
    this->lchild = _lchild;
}
template <class T>
BitNode<T>* BitNode<T>::getLchild() {
    return this->lchild;
}

// 右节点
template <class T>
void BitNode<T>::setRchild(BitNode *_rchild) {
    this->rchild = _rchild;
}

template<class T>
BitNode<T> *BitNode<T>::getRchild() {
    return this->rchild;
};

#endif //UNTITLED4_BITNODE_H
