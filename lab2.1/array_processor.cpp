#include "array_processor.h"
#include <iostream>
#include <iomanip>

int fillRandom(int (&a)[N], int &len) {
    srand(time(nullptr));
    len = (int)(rand()%N+1);
    for(int i=0; i<len; i++) a[i]=(int)(rand()%N+1);
    return 0;
}

int fillFromKeyboard(int (&a)[N], int &len) {
    int input;
    len = 0;
    while(len < 13 && std::cout << len << " " && std::cin >> input) {
        a[len] = input;
        len++;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(len == 0) {
        std::cout << "Масив не може бути пустим.\n";
        return 1;
    }
    return 0;
}

void output(const int *a, int len) {
    for(int i=0; i<len; i++) {
        if(i%5 == 0 && i != 0) std::cout << "\n";
        std::cout << std::right << std::setw(3) << *(a+i);
    }
    std::cout << "\n";
}

//64.	перед останнім елементом, значення якого не є простим числом. Якщо всі числа в масиві прості, додати в початок масиву.
int process64(int *begin, int *mid, int *end) {
    int input;
    std::cout << "Вкажіть число, яке потрібно вставити" << "\n";
    std::cin >> input;
    try {
        int breakPoint = 0;
        process64Backend(begin, mid, end, input, breakPoint);
    } catch (int) {
        throw 1;
    }
}

int process64Backend(int *begin, int *mid, int *end, int input, int &breakPoint) {
    int len = (int)(mid-begin);
    if(len == N) throw 1;
    breakPoint = 0;
    for(int i=len-1; i>=0; i--) {
        if(isPrime(*(begin+i))) continue;
        breakPoint = i;
        break;
    }
    shiftArray(begin, breakPoint, len);
    *(begin+breakPoint)=input;
    len++;
    return len;
}

//89.	перед останнім елементом, значення якого не є простим числом, і перед кожним елементом, значення якого є простим числом.
int process89(int *begin, int *mid, int *end) {
    int input, len, breakPoint = 0;
    std::cout << "Вкажіть число, яке потрібно вставити" << "\n";
    std::cin >> input;
    try {
        len = process64Backend(begin, mid, end, input, breakPoint);
    } catch (int) {
        throw 1;
    }
    for(int i=len-1; i>=0; i--){
        if(i==breakPoint) continue;
        if(!isPrime(*(begin+i))) continue;
        if(len == 13) throw 1;
        if(breakPoint > i) breakPoint++;
        shiftArray(begin, i, len);
        len++;
        *(begin+i)=input;
    }
    return len;
}

void shiftArray(int *begin, const int start, const int len) {
    for(int j=len-1; j>=start; j--) *(begin+j+1)=*(begin+j);
}

bool isPrime(int n) {
    if(n==1) return false;
    for(int i=2; i<=n/2; i++)
        if(n%i==0) return false;
    return true;
}