#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <mutex>
#include <vector>
#include <zconf.h>
#include "src/model/tree/Tree.h"


std::vector<std::string> vec;
std::mutex g_mutex;
void* runFunction(void *e) {
    std::string string = "A(B(D(H,I),E(J,)),C(F,G))";
    auto tree = new Tree<std::string>(string);
    tree ->DispBiTNode();
    g_mutex.lock();
    vec.push_back(tree->resuful);
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