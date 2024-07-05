#include <iostream>
#include "../TreeNode.h"
using namespace std;

void preorderPrint(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    for (auto child : root->children) {
        preorderPrint(child);
    }
}

void postorderPrint(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }

    for (auto child : root->children) {
        postorderPrint(child);
    }

    cout << root->data << " ";
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
    auto root = takeInputLevelWise();
    preorderPrint(root);
    cout << endl;
    postorderPrint(root);
    cout << endl;
    return 0;
}
