/** 376. Wiggle Subsequence */
/** A wiggle sequence is a sequence where the differences between successive numbers strictly 
 *  alternate between positive and negative. The first difference (if one exists) may be either 
 *  positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
 * 
 *  For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) 
 *  alternate between positive and negative. In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] 
 *  are not wiggle sequences. The first is not because its first two differences are positive, 
 *  and the second is not because its last difference is zero.
 *  A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, 
 *  leaving the remaining elements in their original order.
 * 
 *  Given an integer array nums, return the length of the longest wiggle subsequence of nums.
 * 
 *  Example 1:
 *  Input: nums = [1,7,4,9,2,5]
 *  Output: 6
 *  Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
 * 
 *  Example 2:
 *  Input: nums = [1,17,5,10,13,15,10,5,16,8]
 *  Output: 7
 *  Explanation: There are several subsequences that achieve this length.
 *  One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).
 * 
 *  Example 3:
 *  Input: nums = [1,2,3,4,5,6,7,8,9]
 *  Output: 2
 * 
 *  Constraints:
 *  1 <= nums.length <= 1000
 *  0 <= nums[i] <= 1000
 * 
 *  Follow up: Could you solve this in O(n) time?  */

#include <vector>
#include <iostream>

using namespace std;

int cache[2][1000];

void initialize() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 1000; ++j) {
            cache[i][j] = 1;
        }
    }
}

int wiggleMaxLength(vector<int> &nums) {
    initialize();
    
    for (int i = nums.size()-2; i >= 0; --i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j]-nums[i] > 0) {
                cache[0][i] = max(cache[0][i], cache[1][j]+1);
            } else if (nums[j]-nums[i] < 0) {
                cache[1][i] = max(cache[1][i], cache[0][j]+1);
            }
        }
    }
    
    return max(cache[0][0], cache[1][0]);
}

int main() {
    vector<int> nums0 {1,7,4,9,2,5};
    vector<int> nums1 {1,17,5,10,13,15,10,5,16,8};
    vector<int> nums2 {1,2,3,4,5,6,7,8,9};

    int ans0 = wiggleMaxLength(nums0);
    int ans1 = wiggleMaxLength(nums1);
    int ans2 = wiggleMaxLength(nums2);

    cout << ans0 << endl; // 6
    cout << ans1 << endl; // 7
    cout << ans2 << endl; // 2

    return 0;
}


