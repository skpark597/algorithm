/** 226. Invert Binary Tree
Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100  */

#include <cassert>

#include "TreeNode.h"

using namespace std;
using namespace util;

TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) return nullptr;

  TreeNode* new_root = new TreeNode(root->val);

  new_root->left = invertTree(root->right);
  new_root->right = invertTree(root->left);

  return new_root;
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{4, 2, 7, 1, 3, 6, 9});
  TreeNode* root1 = makeTree(vector<int>{2, 1, 3});
  TreeNode* root2 = makeTree(vector<int>{});

  TreeNode* ret0 = invertTree(root0);
  TreeNode* ret1 = invertTree(root1);
  TreeNode* ret2 = invertTree(root2);

  TreeNode* ans0 = makeTree(vector<int>{4, 7, 2, 9, 6, 3, 1});
  TreeNode* ans1 = makeTree(vector<int>{2, 3, 1});
  TreeNode* ans2 = makeTree(vector<int>{});

  assert(isSameTree(ret0, ans0));
  assert(isSameTree(ret1, ans1));
  assert(isSameTree(ret2, ans2));

  return 0;
}
