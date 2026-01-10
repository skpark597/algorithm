/* 300. Longest Increasing Subsequence */
/** A subsequence is a sequence that can be derived from an array by deleting
 * some or no elements without changing the order of the remaining elements. For
 * example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 *
 *  Example 1:
 *  Input: nums = [10,9,2,5,3,7,101,18]
 *  Output: 4
 *  Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 *  Example 2:
 *  Input: nums = [0,1,0,3,2,3]
 *  Output: 4
 *
 *  Example 3:
 *  Input: nums = [7,7,7,7,7,7,7]
 *  Output: 1
 *
 *  Constraints:
 *  1 <= nums.length <= 2500
 *  -10^4 <= nums[i] <= 10^4
 *
 *  Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity? */

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int cache[2500];

int lengthOfLIS(vector<int> &nums) {
  int length = 1;
  int numsLength = nums.size();
  memset(cache, 0, sizeof(cache));

  cache[numsLength - 1] = 1;
  for (int i = numsLength - 2; i >= 0; --i) {
    cache[i] = 1;

    for (int j = i + 1; j < numsLength; ++j) {
      if (nums[j] > nums[i])
        cache[i] = max(cache[i], cache[j] + 1);
    }

    length = max(length, cache[i]);
  }

  return length;
}

int main() {
  vector<int> nums0{10, 9, 2, 5, 3, 7, 101, 18};
  vector<int> nums1{0, 1, 0, 3, 2, 3};
  vector<int> nums2{7, 7, 7, 7, 7, 7, 7};
  vector<int> nums3{4, 10, 4, 3, 8, 9};

  int ans0 = lengthOfLIS(nums0);
  int ans1 = lengthOfLIS(nums1);
  int ans2 = lengthOfLIS(nums2);
  int ans3 = lengthOfLIS(nums3);

  cout << ans0 << endl; // 4
  cout << ans1 << endl; // 4
  cout << ans2 << endl; // 1
  cout << ans3 << endl; // 3
}