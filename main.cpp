#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <mutex>
#include <vector>
#include <zconf.h>
#include "src/model/tree/Tree.h"
#include "src/model/HuffmanCoding/HuffmanCoding.h"


std::vector<char> vec;
std::vector<int> vecH;
std::mutex g_mutex;
void* runFunction(void *e) {
    std::string string = "A(B(D(H,I),E(J,)),C(F,G))";
    std::string find = "A";
    vecH.push_back(2);
    vecH.push_back(30);
    vecH.push_back(20);
    vecH.push_back(16);
    //auto Huffman = new HuffmanCoding<char>(vecH);
    auto tree = new Tree<std::string>(string);
    tree->LeveLOrder();
    g_mutex.lock();
    vec.push_back(tree->findNode('A')->getData());
    g_mutex.unlock();
    pthread_exit(NULL);
}

int main() {
    pthread_t tids[200];
    for(int i = 0; i < 200; ++i)
    {
        int ret = pthread_create(&tids[i], NULL, runFunction, NULL);
    }
    for(int i = 0; i < vec.size() ; i++){
        std::cout << vec[i] << std::endl;
    }
    pthread_exit(NULL);
}