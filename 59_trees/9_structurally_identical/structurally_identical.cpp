#include <iostream>
#include "../TreeNode.h"
using namespace std;

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    auto r1children = root1->children;
    auto r2children = root2->children;

    if (r1children.size() != r2children.size()) {
        return false;
    }

    for (int i = 0; i < r1children.size(); i++) {
        bool iden = areIdentical(r1children[i], r2children[i]);
        if (!iden) {
            return false;
        }
    }

    return root1->data == root2->data;
}

int main() {
    auto root1 = takeInputLevelWise();
    auto root2 = takeInputLevelWise();
    cout << areIdentical(root1, root2) << endl;

    return 0;
}
