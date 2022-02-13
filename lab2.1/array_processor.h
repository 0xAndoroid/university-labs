#include <fstream>

void input(std::ifstream& stream, int *&begin, int *&mid, int *&end);
void output(std::string& path, int *&begin, int *&mid, int *&end);
int process64(int *&begin, int *&mid, int *&end);
int process64Backend(int *&begin, int *&mid, int *&end, int input, int &breakPoint);
int process89(int *&begin, int *&mid, int *&end);
bool isPrime(int n);
void shiftArray(int *&begin, int start, int len);
void increaseLength(int *&begin, int *&mid, int *&end);