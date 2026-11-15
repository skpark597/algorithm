/** 236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:
* The number of nodes in the tree is in the range [2, 10^5].
* -10^9 <= Node.val <= 10^9
* All Node.val are unique
* p != q
* p and q will exist in the tree. */

#include <TreeNode.h>

#include <cassert>
#include <vector>

using namespace std;
using namespace util;

int cur;

void dfs(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& ret) {
  int prev = cur;

  cur += node == p;
  cur += node == q;

  if (node && node->left) dfs(node->left, p, q, ret);
  if (node && node->right) dfs(node->right, p, q, ret);
  if (!ret && prev == 0 && cur == 2) ret = node;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode* ret = nullptr;
  cur = 0;

  dfs(root, p, q, ret);

  return ret;
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{3, 5, 1, 6, 2, 0, 8, NONE, NONE, 7, 4});
  TreeNode* root1 = makeTree(vector<int>{3, 5, 1, 6, 2, 0, 8, NONE, NONE, 7, 4});
  TreeNode* root2 = makeTree(vector<int>{1, 2});

  TreeNode* p0 = root0->left;
  TreeNode* q0 = root0->right;

  TreeNode* p1 = root1->left;
  TreeNode* q1 = root1->left->right->right;

  TreeNode* p2 = root2;
  TreeNode* q2 = root2->left;

  TreeNode* ret0 = lowestCommonAncestor(root0, p0, q0);
  TreeNode* ret1 = lowestCommonAncestor(root1, p1, q1);
  TreeNode* ret2 = lowestCommonAncestor(root2, p2, q2);

  TreeNode* answer0 = root0;
  TreeNode* answer1 = root1->left;
  TreeNode* answer2 = root2;

  assert(isSameTree(ret0, answer0));
  assert(isSameTree(ret1, answer1));
  assert(isSameTree(ret2, answer2));

  return 0;
}