/** 404. Sum of Left Leaves */
/** Find the sum of all left leaves in a given binary tree.
 *  Example:
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 *  There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24. **/

#include <vector>
#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasLeftLeaf (TreeNode *root) {
    TreeNode *left_child = root->left;
    if (left_child ==  nullptr) return false;
    return left_child->left == nullptr && left_child->right == nullptr;
}

int sumOfLeftLeaves(TreeNode *root) {
    int leftSum = 0;
    int rightSum = 0;

    if (root == nullptr) return 0;
        
    if (hasLeftLeaf(root)) {
        leftSum = root->left->val;
    } else {
        leftSum = sumOfLeftLeaves(root->left);
    }

    rightSum = sumOfLeftLeaves(root->right);

    return leftSum + rightSum;
}

int main() {
    TreeNode *node1 = new TreeNode(7);
    TreeNode *node2 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(20, node2, node1);
    TreeNode *node4 = new TreeNode(9);
    TreeNode *node5 = new TreeNode(3, node4, node3);

    //TreeNode *node1 = new TreeNode(1);
    //TreeNode *node2 = new TreeNode(2, node1, nullptr);

    int answer = sumOfLeftLeaves(node5);
    printf("%d\n", answer);

    return 0;
}