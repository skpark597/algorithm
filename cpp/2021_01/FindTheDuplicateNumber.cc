/* 287. Find the Duplicate Number */
/** Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 *  There is only one repeated number in nums, return this repeated number.
 * 
 *  Example 1:
 *  Input: nums = [1,3,4,2,2]
 *  Output: 2
 * 
 *  Example 2:
 *  Input: nums = [3,1,3,4,2]
 *  Output: 3
 * 
 *  Example 3:
 *  Input: nums = [1,1]
 *  Output: 1
 * 
 *  Example 4:
 *  Input: nums = [1,1,2]
 *  Output: 1
 * 
 *  Constraints:
 *  2 <= n <= 3 * 10^4
 *  nums.length == n + 1
 *  1 <= nums[i] <= n
 *  All the integers in nums appear only once except for precisely one integer which appears two or more times.
 * 
 *  Follow up:
 *  How can we prove that at least one duplicate number must exist in nums?
 *  Can you solve the problem without modifying the array nums?
 *  Can you solve the problem using only constant, O(1) extra space?
 *  Can you solve the problem with runtime complexity less than O(n^2)? **/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int findDuplicate(vector<int> &nums) {
    int start = 0;
    int end = 1;
    int answer;

    sort(nums.begin(), nums.end());

    while (end < nums.size()) {
        if (nums[start] == nums[end]) {
            answer = nums[start];
            break;
        }
        start++;
        end++;
    }

    return answer;
}

int main() {
    vector<int> nums0 {1,3,4,2,2};
    int ans0 = findDuplicate(nums0);

    vector<int> nums1 {3,1,3,4,2};
    int ans1 = findDuplicate(nums1);

    vector<int> nums2 {1,1};
    int ans2 = findDuplicate(nums2);

    vector<int> nums3 {1,1,2};
    int ans3 = findDuplicate(nums3);

    cout << ans0 << endl; // 2
    cout << ans1 << endl; // 3
    cout << ans2 << endl; // 1
    cout << ans3 << endl; // 1

    return 0;
}

