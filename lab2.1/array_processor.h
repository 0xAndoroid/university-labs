const int N = 13;

int fillRandom(int (&a)[N], int &len);
int fillFromKeyboard(int (&a)[N], int &len);
void output(const int *a, int len);
int process64(int *begin, int *mid, int *end);
int process64Backend(int *begin, int *mid, int *end, int input, int &breakPoint);
int process89(int *begin, int *mid, int *end);
bool isPrime(int n);
void shiftArray(int *begin, int start, int len);