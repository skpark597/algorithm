/* 377. Combination Sum IV */
/** Given an array of distinct integers nums and a target integer target, 
 *  return the number of possible combinations that add up to target.
 *  The answer is guaranteed to fit in a 32-bit integer.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3], target = 4
 *  Output: 7
 *  Explanation:
 *  The possible combination ways are:
 *  (1, 1, 1, 1)
 *  (1, 1, 2)
 *  (1, 2, 1)
 *  (1, 3)
 *  (2, 1, 1)
 *  (2, 2)
 *  (3, 1)
 *  Note that different sequences are counted as different combinations.
 * 
 *  Example 2:
 *  Input: nums = [9], target = 3
 *  Output: 0
 * 
 *  Constraints:
 *  1 <= nums.length <= 200
 *  1 <= nums[i] <= 1000
 *  All the elements of nums are unique.
 *  1 <= target <= 1000
 *  Follow up: What if negative numbers are allowed in the given array? 
 *  How does it change the problem? What limitation we need to add to the question to allow negative numbers? **/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

uint32_t cache[1001];

int combinationSum4(vector<int> &nums, int target) {
    memset(cache, 0, sizeof(cache));
    cache[0] = 1;

    for (int i = 1; i <= target; ++i) {
        for (int num : nums) {
            if (i >= num) cache[i] += cache[i-num];
        }
    }

    return cache[target];
}

int main() {
    vector<int> nums0 {1,2,3};
    vector<int> nums1 {9};

    int target0 = 4;
    int target1 = 3;

    int ans0 = combinationSum4(nums0, target0);
    int ans1 = combinationSum4(nums1, target1);

    cout << ans0 << endl; // 7
    cout << ans1 << endl; // 0

    return 0;
}

