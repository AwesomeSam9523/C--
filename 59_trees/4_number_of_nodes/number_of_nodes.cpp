#include <iostream>
#include "../TreeNode.h"
using namespace std;

int numberOfNodes(TreeNode<int>* root) {
    int sum = 1;
    for (auto child : root->children) {
        sum += numberOfNodes(child);
    }

    return sum;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << numberOfNodes(root) << endl;
    return 0;
}