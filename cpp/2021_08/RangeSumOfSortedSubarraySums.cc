/** 1508. Range Sum of Sorted Subarray Sums */
/** You are given the array nums consisting of n positive integers.
 *  You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order,
 *  creating a new array of n * (n + 1) / 2 numbers.
 * 
 *  Return the sum of the numbers from index left to index right (indexed from 1), inclusive,
 *  in the new array. Since the answer can be a huge number return it modulo 10^9 + 7.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
 *  Output: 13 
 *  Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array 
 *  [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
 * 
 *  Example 2:
 *  Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
 *  Output: 6
 *  Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. 
 *  The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
 * 
 *  Example 3:
 *  Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
 *  Output: 50
 * 
 *  Constraints:
 *  n == nums.length
 *  1 <= nums.length <= 1000
 *  1 <= nums[i] <= 100
 *  1 <= left <= right <= n * (n + 1) / 2 **/

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int NUM = pow(10,9) + 7;

int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<int> newArr;
    set<int> indices;
    long long answer = 0;
    long long prev = 0;
    int index = 0;
    int number = 0;

    for (int num : nums) {
        newArr.push_back(prev + num);
        prev += num;
    }

    for (int i = nums.size(); indices.size() < n-1;) {
        indices.insert(index);
        index += i--;
    }

    for (int i = 0; newArr.size() <= (n * (n+1) / 2)-1; ++i) {
        if (indices.count(i) != 0) {
            number = newArr[i];
            continue;
        }

        newArr.push_back(newArr[i]-number);
    }

    sort(newArr.begin(), newArr.end());

    for (int i = left-1; i <= right-1; ++i) {
        answer += newArr[i] % NUM;
    }

    return answer % NUM;
}

int main() {
    vector<int> nums0 {1,2,3,4};
    int ans0 = rangeSum(nums0, 4, 1, 5);

    vector<int> nums1 {1,2,3,4};
    int ans1 = rangeSum(nums1, 4, 3, 4);

    vector<int> nums2 {1,2,3,4};
    int ans2 = rangeSum(nums2, 4, 1, 10);

    vector<int> nums3 {1,3};
    int ans3 = rangeSum(nums3, 2, 1, 2);

    cout << ans0 << endl; // 13
    cout << ans1 << endl; // 6
    cout << ans2 << endl; // 50
    cout << ans3 << endl; // 4

    return 0;
}



