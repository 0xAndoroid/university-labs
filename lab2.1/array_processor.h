#include <fstream>
#include <vector>

void input(std::ifstream& stream, std::vector<int> &v);
void output(std::string& path, const std::vector<int>& v);
void process64(std::vector<int> &v);
void process64Backend(std::vector<int> &v, int input, std::vector<int>::iterator breakPoint);
void process89(std::vector<int> &v);
bool isPrime(int n);