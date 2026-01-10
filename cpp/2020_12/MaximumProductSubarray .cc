/* 152. Maximum Product Subarray */
/** Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * 
 *  Example 1:
 *  Input: [2,3,-2,4]
 *  Output: 6
 *  Explanation: [2,3] has the largest product 6.
 * 
 *  Example 2:
 *  Input: [-2,0,-1]
 *  Output: 0
 *  Explanation: The result cannot be 2, because [-2,-1] is not a subarray. **/

/* Kadane's Algorithm을 이용한다. */

#include <vector>
#include <iostream>

using namespace std;

int maxProduct(vector<int> &nums) {
    int cur_min;
    int cur_max;
    int glo_max;
    int cur, temp;

    if (nums.empty()) return 0;

    cur_min = nums[0];
    cur_max = nums[0];
    glo_max = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        cur = nums[i];
        if (cur >= 0) {
            cur_max = max(cur_max * cur, cur);
            cur_min = min(cur_min * cur, cur);
        } else {
            temp = cur_max;
            cur_max = max(cur_min * cur, cur);
            cur_min = min(temp * cur, cur);
        }

        if (cur_max > glo_max) glo_max = cur_max;
    }

    return glo_max;
}

int main() {
    vector<int> nums0 {2,3,-2,4};
    vector<int> nums1 {-2,0,-1};
    vector<int> nums2 {-4,-3,-2};

    int ans0 = maxProduct(nums0);
    int ans1 = maxProduct(nums1);
    int ans2 = maxProduct(nums2);

    cout << ans0 << endl;
    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}

