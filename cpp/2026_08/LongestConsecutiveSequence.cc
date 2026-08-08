/** 128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9 */

#include <cassert>
#include <climits>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int longestConsecutive(vector<int>& nums) {
  int ret = 0;
  unordered_set<int> numSet(nums.begin(), nums.end());

  for (int num : numSet) {
    if (numSet.count(num - 1) == 0) {
      int curNum = num;
      int curLen = 1;

      while (numSet.count(curNum + 1) > 0) {
        curNum++;
        curLen++;
      }

      ret = max(ret, curLen);
    }
  }

  return ret;
}

int main() {
  vector<int> nums0{100, 4, 200, 1, 3, 2};
  vector<int> nums1{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  vector<int> nums2{1, 0, 1, 2};
  vector<int> nums3{1, 3, 2, 4, 3};

  int ret0 = longestConsecutive(nums0);
  int ret1 = longestConsecutive(nums1);
  int ret2 = longestConsecutive(nums2);
  int ret3 = longestConsecutive(nums3);

  assert(ret0 == 4);
  assert(ret1 == 9);
  assert(ret2 == 3);
  assert(ret3 == 4);

  return 0;
}