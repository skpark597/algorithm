/** 530. Minimum Absolute Difference in BST
Given the root of a Binary Search Tree (BST), return the minimum absolute
difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 10^4].
0 <= Node.val <= 10^5 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <vector>

#include "TreeNode.h"

using namespace std;
using namespace util;

struct NodeInfo {
  int min_v, max_v, diff;
};

NodeInfo preorder(TreeNode* root) {
  int min_v = root->val, max_v = root->val, diff = INT_MAX;

  if (root->left) {
    auto [l_min, l_max, l_diff] = preorder(root->left);
    diff = min(diff, abs(root->val - l_max));
    diff = min(diff, l_diff);
    min_v = l_min;
  }

  if (root->right) {
    auto [r_min, r_max, r_diff] = preorder(root->right);
    diff = min(diff, abs(root->val - r_min));
    diff = min(diff, r_diff);
    max_v = r_max;
  }

  return {min_v, max_v, diff};
}

int getMinimumDifference(TreeNode* root) { return preorder(root).diff; }

int main() {
  TreeNode* root0 = makeTree(vector<int>{4, 2, 6, 1, 3});
  TreeNode* root1 = makeTree(vector<int>{1, 0, 48, NONE, NONE, 12, 49});
  TreeNode* root2 = makeTree(vector<int>{236, 104, 701, NONE, 227, NONE, 911});

  int ret0 = getMinimumDifference(root0);
  int ret1 = getMinimumDifference(root1);
  int ret2 = getMinimumDifference(root2);

  assert(ret0 == 1);
  assert(ret1 == 1);
  assert(ret2 == 9);

  return 0;
}
