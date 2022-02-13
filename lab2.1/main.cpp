#include <iostream>
#include "array_processor.h"

using namespace std;

void present() {
    cout << "\"Заповнювач масивів 2000\", К-15, Третьяков Андрій" << "\n";
}

int enterVariantExecution() {
    cout << "1 – викорати варіант 64" << "\n"
    <<"2 – виконати варіант 89" << "\n";
    int input;
    cin >> input;
    return input == 1 ? 64 : 89;
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
    int variantExecution = enterVariantExecution();
    int fillType = enterTypeOfArrayFill();
    int a[N], len;
    switch (fillType) {
        case 1:
            if(fillRandom(a, len) != 0) return 1;
            break;
        case 2:
            if(fillFromKeyboard(a, len) != 0) return 1;
            break;
        default:
            return 0;
    }
    output(a, len);

    try {
        //Toggling between variants. Func process64 executes variant 64; func process89 executes variant 89.
        if(variantExecution == 64)
            len = process64(a, a+len, a+N);
        else if(variantExecution == 89) {
            len = process89(a, a+len, a+N);
        }
    } catch (int) {
        cout << "RANGE CHECK ERROR" << "\n";
        len = 13;
    }
    output(a, len);
}
