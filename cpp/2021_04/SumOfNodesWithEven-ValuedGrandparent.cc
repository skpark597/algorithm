/* 1315. Sum of Nodes with Even-Valued Grandparent */
/** Given a binary tree, return the sum of values of nodes with even-valued grandparent.  
 *  (A grandparent of a node is the parent of its parent, if it exists.)
 *  If there are no nodes with an even-valued grandparent, return 0.
 * 
 *  Example 1:
 *  Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 *  Output: 18
 *  Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
 * 
 *  Constraints:
 *  The number of nodes in the tree is between 1 and 10^4.
 *  The value of nodes is between 1 and 100. **/

#include "/home/seungkyun/Algorithm/LeetCode/common/TreeNode.h"
#include <iostream>
#include <unordered_map>

using namespace std;


void dfs(TreeNode *node, int &sum) {
    if (node == nullptr) return;

    if (node->val % 2 == 0 && node->left != nullptr) {
        TreeNode *left = node->left;
        if (left->left != nullptr) sum += left->left->val;
        if (left->right != nullptr) sum += left->right->val;
    }

    if (node->val % 2 == 0 && node->right != nullptr) {
        TreeNode *right = node->right;
        if (right->left != nullptr) sum += right->left->val;
        if (right->right != nullptr) sum += right->right->val;
    }

    dfs(node->left, sum);
    dfs(node->right, sum);
}

int sumEvenGrandparent(TreeNode* root) {
    int sum = 0;

    dfs(root, sum);
    return sum;
}

int main() {
    TreeNode *node09 = new TreeNode(9);
    TreeNode *node01 = new TreeNode(1);
    TreeNode *node04 = new TreeNode(4);
    TreeNode *node05 = new TreeNode(5);
    TreeNode *node02 = new TreeNode(2, node09, nullptr);
    TreeNode *node07 = new TreeNode(7, node01, node04);
    TreeNode *node01_2 = new TreeNode(1);
    TreeNode *node03 = new TreeNode(3, nullptr, node05);
    TreeNode *node07_2 = new TreeNode(7, node02, node07);
    TreeNode *node08 = new TreeNode(8, node01_2, node03);
    TreeNode *node06 = new TreeNode(6, node07_2, node08);

    int ans0 = sumEvenGrandparent(node06);

    cout << ans0 << endl; // 18

    return 0;
}