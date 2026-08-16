/** 230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of
the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 10^4
0 <= Node.val <= 10^4

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth
smallest frequently, how would you optimize? */

#include <cassert>
#include <vector>

#include "TreeNode.h"

using namespace std;
using namespace util;

int order = 0;

int inorder(TreeNode* root, int k) {
  int val = -1;

  if (root->left) val = inorder(root->left, k);
  if (order == k) return val;

  order++;
  if (order == k) return root->val;

  if (root->right) val = inorder(root->right, k);
  if (order == k) return val;

  return val;
}

int kthSmallest(TreeNode* root, int k) {
  order = 0;
  return inorder(root, k);
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{3, 1, 4, NONE, 2});
  TreeNode* root1 = makeTree(vector<int>{5, 3, 6, 2, 4, NONE, NONE, 1});

  int k0 = 1;
  int k1 = 3;

  int ret0 = kthSmallest(root0, k0);
  int ret1 = kthSmallest(root1, k1);

  assert(ret0 == 1);
  assert(ret1 == 3);

  return 0;
}
