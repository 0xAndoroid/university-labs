#include <iostream>
#include <fstream>

using namespace std;

string getFilePath(const string& message) {
    cout << message << "\n";
    string path;
    getline(cin, path);
    return path;
}

int main() {
    ofstream ofStream;
    string outputFile;
    do {
        outputFile = getFilePath("Введіть шлях файлу виводу");
        outputFile = outputFile.empty() ? "in.txt" : outputFile;
        ofStream.open(outputFile);
        if(!ofStream.good()) cout << "Ви ввели некоректний шлях" << "\n";
    } while (!ofStream.good());
    cout << "Введіть до якого числа потрібно робити послідовність" << "\n";
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) ofStream << i << " ";
}