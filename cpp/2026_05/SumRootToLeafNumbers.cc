/** 129. Sum Root to Leaf Numbers
You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit
integer.

A leaf node is a node with no children.

Example 1:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.


Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10. */

#include <vector>

#include "TreeNode.h"
#include "cassert"
#include "string"

using namespace util;
using namespace std;

vector<string> getDigits(TreeNode* root) {
  if (!root) return {};

  string cur = to_string(root->val);
  if (!(root->left) && !(root->right)) return {cur};

  vector<string> result = getDigits(root->left);
  vector<string> right = getDigits(root->right);

  result.insert(result.end(), right.begin(), right.end());

  for (string& s : result) s = cur + s;

  return result;
}

int sumNumbers(TreeNode* root) {
  int sum = 0;
  for (const string& digit : getDigits(root)) sum += stoi(digit);

  return sum;
}

int main() {
  TreeNode* root0 = makeTree(vector<int>{1, 2, 3});
  TreeNode* root1 = makeTree(vector<int>{4, 9, 0, 5, 1});

  int ret0 = sumNumbers(root0);
  int ret1 = sumNumbers(root1);

  assert(ret0 == 25);
  assert(ret1 == 1026);

  return 0;
}