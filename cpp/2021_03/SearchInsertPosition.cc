/* 35. Search Insert Position */
/** Given a sorted array of distinct integers and a target value, return the index if the target is found. 
 *  If not, return the index where it would be if it were inserted in order.
 * 
 *  Example 1:
 *  Input: nums = [1,3,5,6], target = 5
 *  Output: 2
 * 
 *  Example 2:
 *  Input: nums = [1,3,5,6], target = 2
 *  Output: 1
 * 
 *  Example 3:
 *  Input: nums = [1,3,5,6], target = 7
 *  Output: 4
 * 
 *  Example 4:
 *  Input: nums = [1,3,5,6], target = 0
 *  Output: 0
 * 
 *  Example 5:
 *  Input: nums = [1], target = 0
 *  Output: 0
 * 
 *  Constraints:
 *  1 <= nums.length <= 10^4
 *  -10^4 <= nums[i] <= 10^4
 *  nums contains distinct values sorted in ascending order.
 *  -10^4 <= target <= 10^4 **/

#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    int middle = 0;

    while (left <= right) {
        middle = (left + right) / 2;

        if (target == nums[middle]) {
            return middle;
        } else if (target < nums[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return left;
}

int main() {
    vector<int> nums0 {1,3,5,6};
    vector<int> nums1 {1,3,5,6};
    vector<int> nums2 {1,3,5,6};
    vector<int> nums3 {1,3,5,6};
    vector<int> nums4 {1};

    int ans0 = searchInsert(nums0, 5);
    int ans1 = searchInsert(nums1, 2);
    int ans2 = searchInsert(nums2, 7);
    int ans3 = searchInsert(nums3, 0);
    int ans4 = searchInsert(nums4, 0);

    cout << ans0 << endl; // 2
    cout << ans1 << endl; // 1
    cout << ans2 << endl; // 4
    cout << ans3 << endl; // 0
    cout << ans4 << endl; // 0

    return 0;
}