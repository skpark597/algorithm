/* 1038. Binary Search Tree to Greater Sum Tree */ 
/** Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is 
 *  changed to the original key plus sum of all keys greater than the original key in BST
 *  As a reminder, a binary search tree is a tree that satisfies these constraints:
 *  
 *  The left subtree of a node contains only nodes with keys less than the node's key.
 *  The right subtree of a node contains only nodes with keys greater than the node's key.
 *  Both the left and right subtrees must also be binary search trees.
 *  Note: This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/
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
 *  
 *  Constraints: 
 *  The number of nodes in the tree is in the range [1, 100].
 *  0 <= Node.val <= 100
 *  All the values in the tree are unique.
 *  root is guaranteed to be a valid binary search tree. **/

#include "TreeNode.h"

using namespace std;

int update(TreeNode *node, int value) {
    bool hasRight = node->right != nullptr;
    bool hasLeft = node->left != nullptr;
    
    if (!hasRight) {
        node->val += value;
    } else {
        node->val += update(node->right, value);
    }

    return hasLeft ? update(node->left, node->val) : node->val;
}

TreeNode* bstToGst(TreeNode *root) {
    update(root, 0);
    return root;
}

int main() {
    TreeNode *node01 = new TreeNode(1);
    TreeNode *node00 = new TreeNode(0, nullptr, node01);

    TreeNode *node10 = new TreeNode(0);
    TreeNode *node12 = new TreeNode(2);
    TreeNode *node11 = new TreeNode(1, node10, node12);

    TreeNode *node21 = new TreeNode(1);
    TreeNode *node22 = new TreeNode(2, node21, nullptr);
    TreeNode *node24 = new TreeNode(4);
    TreeNode *node23 = new TreeNode(3, node22, node24);
    
    TreeNode *ans0 = bstToGst(node00);
    TreeNode *ans1 = bstToGst(node11);
    TreeNode *ans2 = bstToGst(node23);

    return 0;
}



