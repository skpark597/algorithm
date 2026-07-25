/** 103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to
right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100 */

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;
using namespace util;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  if (!root) return {};

  vector<vector<int>> result;
  queue<TreeNode*> queue;
  int direction = 0;  // 0: left -> right, 1: right -> left

  queue.push(root);

  while (!queue.empty()) {
    int count = queue.size();
    vector<int> level(count);

    for (int i = 0; i < count; ++i) {
      TreeNode* node = queue.front();
      queue.pop();

      int index = direction ? count - i - 1 : i;
      level[index] = node->val;

      if (node->left) queue.push(node->left);
      if (node->right) queue.push(node->right);
    }

    direction = 1 - direction;
    result.push_back(std::move(level));
  }

  return result;
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{3, 9, 20, NONE, NONE, 15, 7});
  TreeNode* root1 = makeTree(vector<int>{1});
  TreeNode* root2 = makeTree(vector<int>{});

  vector<vector<int>> ret0 = zigzagLevelOrder(root0);
  vector<vector<int>> ret1 = zigzagLevelOrder(root1);
  vector<vector<int>> ret2 = zigzagLevelOrder(root2);

  vector<vector<int>> ans0{{3}, {20, 9}, {15, 7}};
  vector<vector<int>> ans1{{1}};
  vector<vector<int>> ans2{};

  assert(ret0 == ans0);
  assert(ret1 == ans1);
  assert(ret2 == ans2);

  return 0;
}