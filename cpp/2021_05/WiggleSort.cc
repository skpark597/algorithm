/** 324. Wiggle Sort II */
/** Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 *  You may assume the input array always has a valid answer.
 * 
 *  Example 1:
 *  Input: nums = [1,5,1,1,6,4]
 *  Output: [1,6,1,5,1,4]
 *  Explanation: [1,4,1,5,1,6] is also accepted.
 * 
 *  Example 2:
 *  Input: nums = [1,3,2,2,3,1]
 *  Output: [2,3,1,3,1,2]
 * 
 *  Constraints:
 *  1 <= nums.length <= 5 * 10^4
 *  0 <= nums[i] <= 5000
 *  It is guaranteed that there will be an answer for the given input nums.
 *  Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space? */

// Discussion을 보고 구현한 풀이

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int> &nums) {
    vector<int> copy = nums;
    int index = copy.size()-1;

    sort(copy.begin(), copy.end());

    for (int i = 1; i < nums.size(); i += 2) {
        nums[i] = copy[index--];
    }

    for (int i = 0; i < nums.size(); i += 2) {
        nums[i] = copy[index--];
    }

}

int main() {
    vector<int> nums0 {1,5,1,1,6,4};
    vector<int> nums1 {1,3,2,2,3,1};

    wiggleSort(nums0); // 1 6 1 5 1 4 
    wiggleSort(nums1); // 2 3 1 3 1 2 

    for (int iter : nums0) cout << iter << " ";
    cout << endl;
    for (int iter : nums1) cout << iter << " ";

    return 0;
}

