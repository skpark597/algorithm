/** 977. Squares of a Sorted Array */
/** Given an integer array nums sorted in non-decreasing order, 
 *  return an array of the squares of each number sorted in non-decreasing order.
 * 
 *  Example 1:
 *  Input: nums = [-4,-1,0,3,10]
 *  Output: [0,1,9,16,100]
 *  Explanation: After squaring, the array becomes [16,1,0,9,100].
 *  After sorting, it becomes [0,1,9,16,100].
 * 
 *  Example 2:
 *  Input: nums = [-7,-3,2,3,11]
 *  Output: [4,9,9,49,121]
 * 
 *  Constraints:
 *  1 <= nums.length <= 10^4
 *  -10^4 <= nums[i] <= 10^4
 *  nums is sorted in non-decreasing order.
 *  Follow up: Squaring each element and sorting the new array is very trivial, 
 *  could you find an O(n) solution using a different approach? **/

#include <vector>
#include <math.h>
#include <limits.h>
#include <iostream>

using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
    vector<int> answer;
    int start = 0;
    int left, right;

    for (int i = 1; i < nums.size(); ++i) {
        if (abs(nums[i]) < abs(nums[start])) start = i;
    }

    answer.push_back(pow(nums[start], 2));
    left = start-1;
    right = start+1;

    while (true) {
        int leftVal = left >= 0 ? abs(nums[left]) : INT_MAX;
        int rightVal = right < nums.size() ? abs(nums[right]) : INT_MAX;

        if (leftVal == INT_MAX && rightVal == INT_MAX) break;

        if (leftVal <= rightVal) {
            answer.push_back(pow(leftVal, 2));
            left--;
        } else {
            answer.push_back(pow(rightVal, 2));
            right++;
        }
    }

    return answer;
}

int main() {
    vector<int> nums0 {-4,-1,0,3,10};
    vector<int> nums1 {-7,-3,2,3,11};

    vector<int> ans0 = sortedSquares(nums0);
    vector<int> ans1 = sortedSquares(nums1);

    for (int iter : ans0) {
        cout << iter << " ";
    } cout << endl;

    for (int iter : ans1) {
        cout << iter << " ";
    }

    return 0;
}
