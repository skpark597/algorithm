/** 373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]


Constraints:
1 <= nums1.length, nums2.length <= 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 10^4
k <= nums1.length * nums2.length */

#include <array>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
  using Element = array<int, 3>;

  priority_queue<Element, vector<Element>, greater<Element>> min_heap;
  vector<vector<int>> ret;
  ret.reserve(k);

  int initial_len = min((int)nums1.size(), k);

  for (int i = 0; i < nums1.size(); ++i) min_heap.push({nums1[i] + nums2[0], i, 0});

  while (ret.size() < k && !min_heap.empty()) {
    auto [sum, i, j] = min_heap.top();
    min_heap.pop();

    ret.push_back(vector<int>{nums1[i], nums2[j]});

    if (j + 1 < nums2.size()) min_heap.push({nums1[i] + nums2[j + 1], i, j + 1});
  }

  return ret;
}

int main() {
  vector<int> nums01{1, 7, 11};
  vector<int> nums02{2, 4, 6};
  int k0 = 3;

  vector<int> nums11{1, 1, 2};
  vector<int> nums12{1, 2, 3};
  int k1 = 2;

  vector<vector<int>> ret0 = kSmallestPairs(nums01, nums02, k0);
  vector<vector<int>> ret1 = kSmallestPairs(nums11, nums12, k1);

  vector<vector<int>> ans0{{1, 2}, {1, 4}, {1, 6}};
  vector<vector<int>> ans1{{1, 1}, {1, 1}};

  assert(ret0 == ans0);
  assert(ret1 == ans1);

  return 0;
}
