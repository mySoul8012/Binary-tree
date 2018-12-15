//
// Created by ming on 18-12-15.
//

#ifndef UNTITLED4_HUFFMANCODING_H

#include <vector>
#define UNTITLED4_HUFFMANCODING_H

#include "../tree/Tree.h"
#include "../tree/BitNode.h"

// 哈夫曼编码
template <class T>
class HuffmanCoding{
public:
    std::vector<char> vec;
    BitNode<char>* top;
public:
    HuffmanCoding(std::vector<char> _vec){
        this->vec = _vec;
        // 建立b用于临时保存
        std::vector<BitNode<char>*> b;
        // 和vec建立关系
        for(int i = 0; i < vec.size(); i++){
            b[i] = new BitNode<char>(vec[i]);
           b[i]->setLchild(nullptr);
           b[i]->setRchild(nullptr);
        }
        this->top=b[0];

        // 下面开始建立哈夫曼树
        // n个节点，需要循环n-1次建立树
        for(int i = 1; i < b.size(); i++){
            // 定义两个指针，指向第一个和第二个
            int k1= -1, k2;

            // 让指针完成指向第一颗树，第二颗树
            for(int j = 0; j < b.size(); j++){
                // 第一个初始化
                if(b[j] != nullptr && k1 == -1){
                    k1 = j;
                    continue;
                }
                // 第二个初始化
                if(b[j] != nullptr){
                    k2 = j;
                    break;
                }
            }

            // 从当前森林中，取得最小的，第二小的,前提，k1，k2已经完成了指向
            for(int j = k2; j < b.size(); j++){
                // 跳过当前为空的节点
                if(b[j] != nullptr){
                    if(b[j]->getData() < b[k1]->getData()){
                        k2 = k1;
                        k1 = j;
                        // 即 j保存第一小，k1保存第二小
                    }else if(b[j]->getData() < b[k2]->getData()){
                        // k2保存第二小
                        k2 = j;
                    }

                }
            }
            // 开始建立新树，其中k1为第一小，k2为第二小
            auto* tmp = new BitNode<char>(b[k1]->getData() + b[k2]->getData());
            tmp->setRchild(nullptr);
            tmp->setLchild(nullptr);

            // 对于容器内进行清空操作
            b[k1] = tmp;
            b[k2] = nullptr;
        }
    }
    
};


#endif //UNTITLED4_HUFFMANCODING_H
