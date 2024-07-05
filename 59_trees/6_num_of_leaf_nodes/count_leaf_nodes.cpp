#include <iostream>
#include "../TreeNode.h"
using namespace std;

int countLeadNodes(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->children.empty()) {
        return 1;
    }

    int count = 0;
    for (auto child : root->children) {
        count += countLeadNodes(child);
    }

    return count;
}

int main() {
    auto root = takeInputLevelWise();
    cout << countLeadNodes(root) << endl;
    return 0;
}