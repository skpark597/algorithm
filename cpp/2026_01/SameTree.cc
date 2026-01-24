/**100. Same Tree
Given the roots of two binary trees p and q, write a function to check if they
are the same or not.

Two binary trees are considered the same if they are structurally identical, and
the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false


Constraints:
The number of nodes in both trees is in the range [0, 100].
-10^4 <= Node.val <= 10^4 */

#include <cassert>
#include <vector>

#include "TreeNode.h"

using namespace std;
using namespace util;

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (!p && !q) return true;
  if (!p || !q || p->val != q->val) return false;

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
  TreeNode* p0 = makeTree(vector<int>{1, 2, 3});
  TreeNode* q0 = makeTree(vector<int>{1, 2, 3});

  TreeNode* p1 = makeTree(vector<int>{1, 2});
  TreeNode* q1 = makeTree(vector<int>{1, NONE, 3});

  TreeNode* p2 = makeTree(vector<int>{1, 2, 1});
  TreeNode* q2 = makeTree(vector<int>{1, 1, 2});

  bool ret0 = isSameTree(p0, q0);
  bool ret1 = isSameTree(p1, q1);
  bool ret2 = isSameTree(p2, q2);

  assert(ret0 == true);
  assert(ret1 == false);
  assert(ret2 == false);

  return 0;
}
