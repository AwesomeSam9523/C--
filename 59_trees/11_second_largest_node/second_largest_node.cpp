#include <iostream>
#include "../TreeNode.h"
using namespace std;

TreeNode<int>* getLargestNode(TreeNode<int>* root) {
    if (root == nullptr) {
        return root;
    }

    auto largestNode = root;

    for (auto child : root->children) {
        auto childLargest = getLargestNode(child);
        if (childLargest->data > largestNode->data) {
            largestNode = childLargest;
        }
    }

    return largestNode;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if (root == nullptr) {
        return root;
    }

    TreeNode<int>* largestNode = root;
    TreeNode<int>* secondLargestNode = nullptr;

    for (auto child : root->children) {
        auto childLargest = getLargestNode(child);
        cout << "childLargest at " << child->data << " is: " << childLargest->data << endl;
        cout << "largestNode is: " << largestNode->data << " and secondLargestNode is: ";
        if (secondLargestNode) {
            cout << secondLargestNode->data << endl;
        } else {
            cout << "nullptr" << endl;
        }

        if (secondLargestNode && childLargest->data > secondLargestNode->data) {
            secondLargestNode = childLargest;
        }

        if (childLargest->data > largestNode->data) {
            secondLargestNode = largestNode;
            largestNode = childLargest;
        }

    }

    return secondLargestNode;
}

int main() {
    auto root = takeInputLevelWise();
    auto secondLargest = getSecondLargestNode(root);
    if (secondLargest == nullptr) {
        cout << "NULL" << endl;
    } else {
        cout << secondLargest->data << endl;
    }

    return 0;
}
