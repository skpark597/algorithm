/** 334. Increasing Triplet Subsequence */
/** Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
 *  such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3,4,5]
 *  Output: true
 *  Explanation: Any triplet where i < j < k is valid.
 * 
 *  Example 2:
 *  Input: nums = [5,4,3,2,1]
 *  Output: false
 *  Explanation: No triplet exists.
 * 
 *  Example 3:
 *  Input: nums = [2,1,5,0,4,6]
 *  Output: true
 *  Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 * 
 *  Constraints:
 *  1 <= nums.length <= 5 * 10^5
 *  -2^31 <= nums[i] <= 2^31 - 1
 * 
 *  Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity? */

// Accepted 되었으나 너무 복잡한 솔루션... Discussion 을 보고 2에서 다시 구현.

#include <vector>
#include <iostream>

using namespace std;

// Find next top element
int findNextTop(int &nextFirst, int &index, vector<int> &nums) {
    int count = 1;

    for (;index < nums.size(); ++index) {
        if (index == nums.size()-1 || nums[index] < nums[index+1]) break;
    }

    nextFirst = index;
    for (;index < nums.size(); ++index) {
        if (index == nums.size()-1 || nums[index] >= nums[index+1]) break;
        count++;
        if (count == 3) return count;
    }

    return count;
}

bool increasingTriplet(vector<int> &nums) {
    int first = 0;
    int cur = 0;
    int count = 2;
    int index = 0;

    if (nums.size() < 3) return false;
    
    for (;index < nums.size(); ++index) {
        if (index == nums.size()-1 || nums[index] < nums[index+1]) break;
    }

    first = index++;
    if (index == nums.size()-1) return false;
    cur = index;

    for (;index < nums.size(); ++index) {
        if (nums[cur] < nums[index]) {
            cur = index;
            count++;
        } else if (nums[first] < nums[index] && nums[index] <= nums[cur]) {
            cur = index;
        } else {
            int nextFirst;
            int newCount = findNextTop(nextFirst, index, nums);

            if (newCount == 1) {
                return false;
            } else if (newCount == 3 || newCount == 2 && nums[index] > nums[cur]) {
                return true;
            } else {
                first = nextFirst;
                cur = index;
                count = newCount;
            }
        }
            
        if (count == 3) return true;
    }
        
    return false;
}

int main() {
    vector<int> nums0 {1,2,3,4,5};
    vector<int> nums1 {5,4,3,2,1};
    vector<int> nums2 {2,1,5,0,4,6};
    vector<int> nums3 {20,100,10,12,5,13};
    vector<int> nums4 {1,5,0,4,1,3};
    vector<int> nums5 {5,1,6};
    vector<int> nums6 {5,1,5,5,2,5,4};
    vector<int> nums7 {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,-1,1,1,1,1,1,1,0};
    vector<int> nums8 {1,0,0,0,0,10,0,0,0,0,0,0,100000000};

    bool ans0 = increasingTriplet(nums0);
    bool ans1 = increasingTriplet(nums1);
    bool ans2 = increasingTriplet(nums2);
    bool ans3 = increasingTriplet(nums3);
    bool ans4 = increasingTriplet(nums4);
    bool ans5 = increasingTriplet(nums5);
    bool ans6 = increasingTriplet(nums6);
    bool ans7 = increasingTriplet(nums7);
    bool ans8 = increasingTriplet(nums8);

    cout << ans0 << endl; // true
    cout << ans1 << endl; // false
    cout << ans2 << endl; // true
    cout << ans3 << endl; // true
    cout << ans4 << endl; // true
    cout << ans5 << endl; // false
    cout << ans6 << endl; // true
    cout << ans7 << endl; // false
    cout << ans8 << endl; // true

    return 0;
}
