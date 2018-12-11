//
// Created by ming on 18-12-12.
//
#include <iostream>
#include <thread>       // 1.

void greeting() {       // 2.
    std::cout << "Hello multithread!" << std::endl;
    return;
}

//int main() {
//    std::thread t{greeting};    // 3.
 //   t.join();                   // 4.
  //  return 0;
//}