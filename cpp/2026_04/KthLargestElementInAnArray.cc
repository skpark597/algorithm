/** 215. Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4 */

#include <cassert>
#include <queue>
#include <vector>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
  priority_queue<int> max_heap(nums.begin(), nums.end());
  for (int i = 0; i < k - 1; ++i) max_heap.pop();

  return max_heap.top();
}

int main() {
  vector<int> nums0{3, 2, 1, 5, 6, 4};
  vector<int> nums1{3, 2, 3, 1, 2, 4, 5, 5, 6};

  int k0 = 2;
  int k1 = 4;

  int ret0 = findKthLargest(nums0, k0);
  int ret1 = findKthLargest(nums1, k1);

  assert(ret0 == 5);
  assert(ret1 == 4);

  return 0;
}
