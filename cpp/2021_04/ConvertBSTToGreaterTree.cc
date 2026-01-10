/** 538. Convert BST to Greater Tree */
/** Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the 
 *  original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 * 
 *  As a reminder, a binary search tree is a tree that satisfies these constraints:
 *  The left subtree of a node contains only nodes with keys less than the node's key.
 *  The right subtree of a node contains only nodes with keys greater than the node's key.
 *  Both the left and right subtrees must also be binary search trees.
 *  Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 * 
 *  Example 1:
 *  Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
 *  Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 * 
 *  Example 2:
 *  Input: root = [0,null,1]
 *  Output: [1,null,1]
 *  
 *  Example 3:
 *  Input: root = [1,0,2]
 *  Output: [3,3,2]
 * 
 *  Example 4:
 *  Input: root = [3,2,4,1]
 *  Output: [7,9,4,10]
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 10^4].
 *  -10^4 <= Node.val <= 10^4
 *  All the values in the tree are unique.
 *  root is guaranteed to be a valid binary search tree. **/


#include "/home/seungkyun/Algorithm/LeetCode/common/TreeNode.h"
#include <iostream>

using namespace std;

int convertInternal(TreeNode *root, int &preSum) {
    if (root->right == nullptr) {
        root->val += preSum;
    } else {
        root->val += convertInternal(root->right, preSum);
    }

    return root->left == nullptr ? root->val : convertInternal(root->left, root->val);
}

TreeNode* convertBST(TreeNode *root) {
    int init = 0;
    if (root == nullptr) return nullptr;
    
    convertInternal(root, init);
    return root;
}

int main() {
    TreeNode *node0_8 = new TreeNode(8);
    TreeNode *node0_7 = new TreeNode(7, nullptr, node0_8);
    TreeNode *node0_5 = new TreeNode(5);
    TreeNode *node0_6 = new TreeNode(6, node0_5, node0_7);
    TreeNode *node0_3 = new TreeNode(3);
    TreeNode *node0_2 = new TreeNode(2, nullptr, node0_3);
    TreeNode *node0_0 = new TreeNode(0);
    TreeNode *node0_1 = new TreeNode(1, node0_0, node0_2);
    TreeNode *node0_4 = new TreeNode(4, node0_1, node0_6);

    TreeNode *ans0 = convertBST(node0_4);

    return 0;
}
