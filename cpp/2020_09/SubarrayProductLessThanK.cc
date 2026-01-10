/* 713. Subarray Product Less Than K */
/* Your are given an array of positive integers nums.
 * Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.
 * Example 1:
 * Input: nums = [10, 5, 2, 6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
 * 
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
 * Note:
 * 0 < nums.length <= 50000.
 * 0 < nums[i] < 1000.
 * 0 <= k < 10^6
 * 
 * Hide Hint #1  
 * For each j, let opt(j) be the smallest i so that nums[i] * nums[i+1] * ... * nums[j] is less than k. opt is an increasing function.**/

#include <vector>
#include <iostream>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int opt = 0;
    int prod = 1;
    int count = 0;

    for (int j=0; j < nums.size(); ++j) {
        if (nums[j] >= k) {
            opt = j+1;
            continue;
        }
        prod *= nums[j];
        for (;opt <= j;++opt) {
            if (prod < k) break;
            prod /= nums[opt];
        }
        count += j-opt+1;
    }

    return count;
}

int main() {
    vector<int> nums {1,2,3};
    int answer = numSubarrayProductLessThanK(nums, 0);
    cout << answer << endl;
    return 0;
}