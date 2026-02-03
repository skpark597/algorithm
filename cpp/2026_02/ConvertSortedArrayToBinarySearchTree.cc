/** 108. Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order,
convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in a strictly increasing order. */

#include <cassert>
#include <vector>

#include "TreeNode.h"

using namespace std;
using namespace util;

TreeNode* makeBST(vector<int>& nums, int start, int end) {
  if (start > end) return nullptr;

  int mid = start + (end - start) / 2;

  TreeNode* root = new TreeNode(nums[mid]);

  root->left = makeBST(nums, start, mid - 1);
  root->right = makeBST(nums, mid + 1, end);

  return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  return makeBST(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> nums0{-10, -3, 0, 5, 9};
  vector<int> nums1{1, 3};

  TreeNode* ret0 = sortedArrayToBST(nums0);
  TreeNode* ret1 = sortedArrayToBST(nums1);

  TreeNode* ans0 = makeTree(vector<int>{0, -10, 5, NONE, -3, NONE, 9});
  TreeNode* ans1 = makeTree(vector<int>{1, NONE, 3});

  assert(isSameTree(ret0, ans0));
  assert(isSameTree(ret1, ans1));

  return 0;
}
