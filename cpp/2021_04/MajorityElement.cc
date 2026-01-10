/* 169. Majority Element */
/** Given an array nums of size n, return the majority element.
 *  The majority element is the element that appears more than ⌊n / 2⌋ times. 
 *  You may assume that the majority element always exists in the array.
 * 
 *  Example 1:
 *  Input: nums = [3,2,3]
 *  Output: 3
 * 
 *  Example 2:
 *  Input: nums = [2,2,1,1,1,2,2]
 *  Output: 2
 *  
 *  Constraints:
 *  n == nums.length
 *  1 <= n <= 5 * 10^4
 *  -2^31 <= nums[i] <= 2^31 - 1
 *  Follow-up: Could you solve the problem in linear time and in O(1) space? */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int majorityElement(vector<int> &nums) {
    int num = nums[0];
    int size = nums.size();
    int count = 0;

    sort(nums.begin(), nums.end());

    for (int iter : nums) {
        if (num == iter) {
            count++;
            if (count > size / 2) break;
        } else {
            num = iter;
            count = 1;
        }
    }

    return num;
}

int main() {
    vector<int> nums0 {3,2,3};
    vector<int> nums1 {2,2,1,1,1,2,2};

    int ans0 = majorityElement(nums0);
    int ans1 = majorityElement(nums1);

    cout << ans0 << endl; // 3 
    cout << ans1 << endl; // 2

    return 0;
}

