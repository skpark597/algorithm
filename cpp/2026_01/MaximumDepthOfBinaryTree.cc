/**104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from
the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100*/

#include <cassert>
#include <queue>

#include "TreeNode.h"

using namespace std;
using namespace util;

int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;

  queue<TreeNode*> queue({root});
  int depth = 0;

  while (!queue.empty()) {
    depth++;

    for (int i = queue.size(); i > 0; --i) {
      TreeNode* node = queue.front();
      queue.pop();

      if (node->left) queue.push(node->left);
      if (node->right) queue.push(node->right);
    }
  }

  return depth;
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{3, 9, 20, NONE, NONE, 15, 7});
  TreeNode* root1 = makeTree(vector<int>{1, NONE, 2});

  int ret0 = maxDepth(root0);
  int ret1 = maxDepth(root1);

  assert(ret0 == 3);
  assert(ret1 == 2);

  return 0;
}
