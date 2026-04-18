/** 114. Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child
pointer points to the next node in the list and the left child pointer is always
null. The "linked list" should be in the same order as a pre-order traversal of
the binary tree.

Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

Follow up: Can you flatten the tree in-place (with O(1) extra space)? */

#include <cassert>

#include "TreeNode.h"

using namespace std;
using namespace util;

void solve(TreeNode* root, TreeNode*& prev) {
  if (!root) return;

  solve(root->right, prev);
  solve(root->left, prev);

  root->right = prev;
  root->left = nullptr;
  prev = root;
}

void flatten(TreeNode* root) {
  TreeNode* prev = nullptr;
  solve(root, prev);
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{1, 2, 5, 3, 4, NONE, 6});
  TreeNode* root1 = makeTree(vector<int>{});
  TreeNode* root2 = makeTree(vector<int>{0});

  flatten(root0);
  flatten(root1);
  flatten(root2);

  TreeNode* ans0 =
      makeTree(vector<int>{1, NONE, 2, NONE, 3, NONE, 4, NONE, 5, NONE, 6});
  TreeNode* ans1 = makeTree(vector<int>{});
  TreeNode* ans2 = makeTree(vector<int>{0});

  assert(isSameTree(root0, ans0));
  assert(isSameTree(root1, ans1));
  assert(isSameTree(root2, ans2));

  return 0;
}
