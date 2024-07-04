#include <iostream>
#include "../TreeNode.h"
using namespace std;

TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter data:";
    cin >> rootData;
    auto root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of " << rootData << ":";
    cin >> n;

    for (int i = 0; i < n; i++) {
        auto child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++) {
        cout << root->children.at(i)->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++) {
        printTree(root->children.at(i));
    }
}

int main() {
    /*TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);*/

    auto root = takeInput();
    printTree(root);

    // TODO: Delete the tree
}
