#include <iostream>
#include "../TreeNode.h"
using namespace std;

int getNodeSum(TreeNode<int>* root) {
    int sum = root->data;

    for (auto child : root->children) {
        sum += child->data;
    }

    return sum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    int sum = getNodeSum(root);
    auto highestRoot = root;

    for (auto child : root->children) {
        auto childSumNode = maxSumNode(child);
        int childSum = getNodeSum(childSumNode);

        if (childSum > sum) {
            highestRoot = childSumNode;
            sum = childSum;
        }
    }

    return highestRoot;
}

int main() {
    auto root = takeInputLevelWise();
    cout << maxSumNode(root) << endl;

    return 0;
}
