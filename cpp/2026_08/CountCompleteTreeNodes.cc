/** 222. Count Complete Tree Nodes
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all
nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1


Constraints:
The number of nodes in the tree is in the range [0, 5 * 10^4].
0 <= Node.val <= 5 * 10^4
The tree is guaranteed to be complete. */

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;
using namespace util;

bool isNodeExist(TreeNode* root, int idx, int height) {
  TreeNode* node = root;

  for (int bit = height - 1; bit >= 0; --bit) {
    if (!node) return false;

    if (idx & (1 << bit)) {
      node = node->right;
    } else {
      node = node->left;
    }
  }

  return node != nullptr;
}

int countNodes(TreeNode* root) {
  if (root == nullptr) return 0;

  TreeNode* node = root;
  int height = -1;

  while (node) {
    node = node->left;
    height++;
  }

  int left = 1 << height, right = (1 << (height + 1)) - 1;

  while (left <= right) {
    int middle = left + (right - left) / 2;

    if (isNodeExist(root, middle, height)) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  return right;
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{1, 2, 3, 4, 5, 6});
  TreeNode* root1 = makeTree(vector<int>{});
  TreeNode* root2 = makeTree(vector<int>{1});

  int ret0 = countNodes(root0);
  int ret1 = countNodes(root1);
  int ret2 = countNodes(root2);

  assert(ret0 == 6);
  assert(ret1 == 0);
  assert(ret2 == 1);

  return 0;
}
