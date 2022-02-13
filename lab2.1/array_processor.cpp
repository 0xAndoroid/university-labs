#include "array_processor.h"
#include <iostream>
#include <iomanip>

void input(std::ifstream& str, int *&begin, int *&mid, int *&end) {
    int in;
    for(int i=0; str >> in; i++) {
        if(mid == end)
            increaseLength(begin, mid, end);
        *(begin+i) = in;
        mid++;
    }
    if(begin == mid) {
        exit(1);
    }
}

void output(std::string& path, int *&begin, int *&mid, int *&end) {
    int len = (int)(mid-begin);
    std::ofstream str;
    str.open(path);
    for(int i=0; i<len; i++) {
        if(i%5 == 0 && i != 0) str << "\n";
        str << std::right << std::setw(5) << *(begin+i);
    }
    str << "\n";
}

//64.	перед останнім елементом, значення якого не є простим числом. Якщо всі числа в масиві прості, додати в початок масиву.
int process64(int *&begin, int *&mid, int *&end) {
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

int process64Backend(int *&begin, int *&mid, int *&end, int input, int &breakPoint) {
    int len = (int)(mid-begin);
    if(len == end-begin) increaseLength(begin, mid, end);
    breakPoint = 0;
    for(int i=len-1; i>=0; i--) {
        if(isPrime(*(begin+i))) continue;
        breakPoint = i;
        break;
    }
    shiftArray(begin, breakPoint, len);
    *(begin+breakPoint)=input;
    len++;
    mid = begin + len;
    return len;
}

//89.	перед останнім елементом, значення якого не є простим числом, і перед кожним елементом, значення якого є простим числом.
int process89(int *&begin, int *&mid, int *&end) {
    int input, len, breakPoint = 0;
    std::cout << "Вкажіть число, яке потрібно вставити" << "\n";
    std::cin >> input;
    len = process64Backend(begin, mid, end, input, breakPoint);
    for(int i=len-1; i>=0; i--){
        if(i==breakPoint) continue;
        if(!isPrime(*(begin+i))) continue;
        if(len == end-begin) increaseLength(begin, mid, end);
        if(breakPoint > i) breakPoint++;
        shiftArray(begin, i, len);
        len++;
        mid = begin + len;
        *(begin+i)=input;
    }
    return len;
}

void shiftArray(int *&begin, const int start, const int len) {
    for(int j=len-1; j>=start; j--) *(begin+j+1)=*(begin+j);
}

bool isPrime(int n) {
    if(n==1) return false;
    for(int i=2; i<=n/2; i++)
        if(n%i==0) return false;
    return true;
}

void increaseLength(int *&begin, int *&mid, int *&end) {
    int len = (int)(end-begin);
    std::cout << "MEMORY ALLOC: " << len << " " << len*2 << "\n";
    int *newArray = new(std::nothrow) int[len*2];
    if(newArray == nullptr) {
        std::cout << "FAILED" << "\n";
        exit(1);
    }
    for(int i=0; i<(end-begin); i++)
        *(newArray+i) = *(begin+i);
    delete [] begin;
    begin = newArray;
    mid = newArray + len;
    end = newArray + 2*len;
}