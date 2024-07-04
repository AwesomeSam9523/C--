#include <iostream>
#include <queue>
#include "../TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data:";
    cin >> rootData;
    auto root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << ":";
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++) {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << ":";
            cin >> childData;

            auto childNode = new TreeNode<int>(childData);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
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
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);

    return 0;
}