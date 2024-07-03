#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &input) {
    for (int i = 0; i < input.size()/2; i++) {
        int back = input.back();
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {

        }

        cout << "\n";
    }
}