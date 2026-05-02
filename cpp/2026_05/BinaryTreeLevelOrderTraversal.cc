/** 102. Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level
by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000 */

#include <cassert>
#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;
using namespace util;

vector<vector<int>> levelOrder(TreeNode* root) {
  if (!root) return {};

  vector<vector<int>> result;
  queue<TreeNode*> q({root});

  while (!q.empty()) {
    int count = q.size();
    auto& level = result.emplace_back();
    level.reserve(count);

    while (count--) {
      TreeNode* node = q.front();
      q.pop();

      level.push_back(node->val);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }

  return result;
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{3, 9, 20, NONE, NONE, 15, 7});
  TreeNode* root1 = makeTree(vector<int>{1});
  TreeNode* root2 = makeTree(vector<int>{});

  vector<vector<int>> ans0{{3}, {9, 20}, {15, 7}};
  vector<vector<int>> ans1{{1}};
  vector<vector<int>> ans2{};

  vector<vector<int>> ret0 = levelOrder(root0);
  vector<vector<int>> ret1 = levelOrder(root1);
  vector<vector<int>> ret2 = levelOrder(root2);

  assert(ret0 == ans0);
  assert(ret1 == ans1);
  assert(ret2 == ans2);

  return 0;
}
