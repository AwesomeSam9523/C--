#include <iostream>
#include <climits>
#include "../TreeNode.h"
using namespace std;

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if (root == nullptr) {
        return root;
    }

    int difference = root->data - x;
    if (difference <= 0) {
        difference = INT_MAX;
    }

    cout << root->data << " " << x << " " << difference << endl;

    auto node = root;

    for (auto child : root->children) {
        auto childLargerElement = getNextLargerElement(child, x);
        if (childLargerElement == nullptr) {
            continue;
        }

        int childDifference = childLargerElement->data - x;
        cout << "cd: " << childDifference << endl;
        if (childDifference == 0) {
            continue;
        }

        if (childDifference < difference) {
            difference = childDifference;
            node = childLargerElement;
        }
    }

    if (difference == INT_MAX || difference < 0) {
        return nullptr;
    }

    return node;
}

int main() {
    auto root = takeInputLevelWise();
    int x;
    cin >> x;
    auto largerElement = getNextLargerElement(root, x);
    if (largerElement == nullptr) {
        cout << "NULL" << endl;
    } else {
        cout << largerElement->data << endl;
    }

    return 0;
}
