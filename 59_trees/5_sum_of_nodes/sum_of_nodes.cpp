#include <iostream>
#include "../TreeNode.h"
using namespace std;

int sumOfNodes(TreeNode<int>* root) {
    int sum = root->data;
    for (auto child : root->children) {
        sum += sumOfNodes(child);
    }

    return sum;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << sumOfNodes(root) << endl;
    return 0;
}