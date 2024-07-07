#include <iostream>
#include <queue>
#include "../TreeNode.h"
using namespace std;


void printTreeLevelWise(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode<int>*> pending;
    pending.push(root);

    while (!pending.empty()) {
        auto front = pending.front();
        pending.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++) {
            auto child = front->children[i];
            cout << child->data;
            if (i != front->children.size() - 1) {
                cout << ",";
            }
            pending.push(child);
        }
        cout << endl;
    }
}

int main() {
    auto root = takeInputLevelWise();
    printTreeLevelWise(root);
    return 0;
}