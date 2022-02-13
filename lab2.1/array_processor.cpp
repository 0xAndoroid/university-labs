#include "array_processor.h"
#include <iostream>
#include <iomanip>

const int N = 13;

void fillRandom(int (&a)[N], int &len) {
    srand(time(nullptr));
    len = (int)(rand()%N+1);
    for(int i=0; i<len; i++) a[i]=(int)(rand()%N+1);
}

void fillFromKeyboard(int (&a)[N], int &len) {
    int input;
    len = 0;
    while(len < 13 && std::cout << len << " " && std::cin >> input) {
        a[len] = input;
        len++;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(len == 0)
        std::cout << "Масив не може бути пустим.\n";
}

void output(const int *a, int len) {
    for(int i=0; i<len; i++) {
        if(i%5 == 0 && i != 0) std::cout << "\n";
        std::cout << std::right << std::setw(3) << *(a+i);
    }
}