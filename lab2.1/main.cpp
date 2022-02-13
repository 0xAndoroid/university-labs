#include <iostream>
#include "array_processor.h"
#include <string>
#include <vector>

using namespace std;

void present() {
    cout << "\"Заповнювач масивів 3000\", К-15, Третьяков Андрій" << "\n";
}

int enterVariantExecution() {
    cout << "1 – викорати варіант 64" << "\n"
    <<"2 – виконати варіант 89" << "\n";
    int input;
    cin >> input;
    return input == 1 ? 64 : 89;
}

string getFilePath(const string& message) {
    cout << message << "\n";
    string path;
    getline(cin, path);
    return path;
}

int main() {
    present();
    ifstream ifStream;
    ofstream ofStream;
    string outputFile;
    do {
        string inputFile =  getFilePath("Введіть шлях файлу вводу");
        inputFile = inputFile.empty() ? "in.txt" : inputFile;
        ifStream.open(inputFile);
        if(!ifStream.good()) cout << "Ви ввели некоректний шлях" << "\n";
    } while (!ifStream.good());
    do {
        outputFile = getFilePath("Введіть шлях файлу виводу");
        outputFile = outputFile.empty() ? "out.txt" : outputFile;
        ofStream.open(outputFile);
        if(!ofStream.good()) cout << "Ви ввели некоректний шлях" << "\n";
    } while (!ofStream.good());
    int variantExecution = enterVariantExecution();
    vector<int> vec;
    input(ifStream, vec);
    if(variantExecution == 64) process64(vec);
    else if(variantExecution == 89) process89(vec);
    output(outputFile, vec);
}
