#include <iostream>
#include "array_processor.h"

using namespace std;

void present() {
    cout << "\"Заповнювач масивів 2000\", К-15, Третьяков Андрій" << "\n";
}

int enterTypeOfArrayFill() {
    cout << "1 – заповнити масив псевдовипадковими числами" << "\n"
    <<"2 – ввести числа за допомогою клавіатури" << "\n"
    << "інше число – закінчити роботу" << "\n";
    int input;
    cin >> input;
    return input;
}

int main() {
    present();
    int fillType = enterTypeOfArrayFill();
    int a[13], len;
    switch (fillType) {
        case 1:
            fillRandom(a, len);
            break;
        case 2:
            fillFromKeyboard(a, len);
            break;
        default:
            return 0;
    }
    output(a, len);
}
