#include "array_processor.h"
#include <iostream>
#include <iomanip>

void input(std::ifstream& stream, std::vector<int> &v) {
    int in;
    while (stream >> in) v.push_back(in);
    if(v.empty()) exit(1);
}

void output(std::string& path, const std::vector<int>& v) {
    std::ofstream str;
    str.open(path);
    int i = 0;
    for(auto el : v) {
        if(i%5 == 0 && i != 0) str << "\n";
        str << std::right << std::setw(5) << el;
        i++;
    }
    str << "\n";
}

//64.	перед останнім елементом, значення якого не є простим числом. Якщо всі числа в масиві прості, додати в початок масиву.
void process64(std::vector<int> &v) {
    int input;
    std::cout << "Вкажіть число, яке потрібно вставити" << "\n";
    std::cin >> input;
    try {
        auto breakPoint = v.begin();
        process64Backend(v, input, breakPoint);
    } catch (int) {
        throw 1;
    }
}

void process64Backend(std::vector<int> &v, int input, std::vector<int>::iterator breakPoint) {
    breakPoint = v.begin();
    for(auto i=v.end()-1; i!=v.begin(); i--) {
        if(isPrime(*i)) continue;
        breakPoint = i;
        break;
    }
    v.insert(breakPoint, input);
}

//89.	перед останнім елементом, значення якого не є простим числом, і перед кожним елементом, значення якого є простим числом.
void process89(std::vector<int> &v) {
    int input;
    auto breakPoint = v.begin();
    std::cout << "Вкажіть число, яке потрібно вставити" << "\n";
    std::cin >> input;
    process64Backend(v, input, breakPoint);
    for(auto i = v.end()-1; i!=v.begin(); i--){
        if(i==breakPoint) continue;
        if(!isPrime(*i)) continue;
        if(breakPoint > i) breakPoint++;
        v.insert(i, input);
    }
}

bool isPrime(int n) {
    if(n==1) return false;
    for(int i=2; i<=n/2; i++)
        if(n%i==0) return false;
    return true;
}