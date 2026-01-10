/* 532. K-diff Pairs in an Array */
/** Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
 *  
 * 0 <= i, j < nums.length
 * i != j
 * a <= b
 * b - a == k
 * 
 * Example 1:
 * Input: nums = [3,1,4,1,5], k = 2
 * Output: 2
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
 * Although we have two 1s in the input, we should only return the number of unique pairs.
 * 
 * Example 2:
 * Input: nums = [1,2,3,4,5], k = 1
 * Output: 4
 * Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
 * 
 * Example 3:
 * Input: nums = [1,3,1,5,4], k = 0
 * Output: 1
 * Explanation: There is one 0-diff pair in the array, (1, 1).
 * 
 * Example 4:
 * Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
 * Output: 2
 * 
 * Example 5:
 * Input: nums = [-1,-2,-3], k = 1
 * Output: 2
 * 
 * Constraints:
 * 1 <= nums.length <= 104
 * -107 <= nums[i] <= 107
 * 0 <= k <= 107 **/

/** discussion에 있는 풀이로 O(n) **/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

int findPairs(vector<int>& nums, int k) {
    if (k<0) return 0;

    unordered_set<int> prevNum, answer;
    for (int num : nums) {
        if (prevNum.count(num-k)) answer.insert(num-k);
        if (prevNum.count(num+k)) answer.insert(num);
        prevNum.insert(num);
    }
    return answer.size();
}

int main() {
    vector<int> nums {1,2,4,4,3,3,0,9,2,3};
    int k = 3;
    int answer = findPairs(nums,k);
    cout << answer << endl;

    return 0;
}