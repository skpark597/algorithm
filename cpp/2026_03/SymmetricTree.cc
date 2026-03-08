/** 101. Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100 */

#include <cassert>
#include <cmath>
#include <deque>
#include <optional>
#include <vector>

#include "TreeNode.h"

using namespace std;
using namespace util;

int EMPTY = 101;

bool isMirror(TreeNode* t1, TreeNode* t2) {
  if (!t1 && !t2) return true;
  if ((t1 && !t2) || (!t1 && t2) || (t1->val != t2->val)) return false;

  return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) { return isMirror(root, root); }

bool isSymmetricInitial(TreeNode* root) {
  /** Initial Approach: BFS with Level-wise Palindrome Check */

  deque<TreeNode*> queue{root};

  while (!queue.empty()) {
    int num_nodes = queue.size();
    vector<int> vals(num_nodes, EMPTY);

    for (int i = 0; i < num_nodes; ++i) {
      TreeNode* cur_node = queue.front();
      queue.pop_front();

      if (!cur_node) continue;

      queue.push_back(cur_node->left);
      queue.push_back(cur_node->right);
      vals[i] = cur_node->val;
    }

    for (int i = 0; i < num_nodes / 2; ++i)
      if (vals[i] != vals[num_nodes - 1 - i]) return false;
  }

  return true;
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{1, 2, 2, 3, 4, 4, 3});
  TreeNode* root1 = makeTree(vector<int>{1, 2, 2, NONE, 3, NONE, 3});

  bool ret0 = isSymmetric(root0);
  bool ret1 = isSymmetric(root1);

  assert(ret0 == true);
  assert(ret1 == false);

  return 0;
}
