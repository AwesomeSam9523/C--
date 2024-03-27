#include <iostream>
#include "stack_array.cpp"
using namespace std;

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.isEmpty() << endl;
    stack.push(30);
    cout << stack.top() << endl;
    cout << stack.size() << endl;

    return 0;
}