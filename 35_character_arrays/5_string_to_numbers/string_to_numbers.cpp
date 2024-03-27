#include <iostream>
using namespace std;

int helper(char *input, int length) {
    if (length == 0)
        return 0;
    char ele = input[length-1];
//    cout << "length: " << length << " " << ((int)ele - 48) << endl;
    return ((int)ele - 48) + helper(input, length-1)*10;
}

int stringToNumber(char input[]) {
    int length = 0;
    for (; input[length] != '\0'; length++);
    return helper(input, length);
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
