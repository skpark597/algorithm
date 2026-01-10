/* 922. Sort Array By Parity II */
/** Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
 *  Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
 *  Return any answer array that satisfies this condition.
 * 
 *  Example 1:
 *  Input: nums = [4,2,5,7]
 *  Output: [4,5,2,7]
 *  Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 * 
 *  Example 2:
 *  Input: nums = [2,3]
 *  Output: [2,3]
 * 
 *  Constraints:
 *  2 <= nums.length <= 2 * 10^4
 *  nums.length is even.
 *  Half of the integers in nums are even.
 *  0 <= nums[i] <= 1000 **/

#include <vector>
#include <iostream>

using namespace std;

vector<int> sortArrayByParityII(vector<int> &nums) {
    vector<int> answer (nums.size(), 0);
    int oddIndex = 1;
    int evenIndex = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] % 2 == 0) {
            answer[evenIndex] = nums[i];
            evenIndex += 2;
        } else {
            answer[oddIndex] = nums[i];
            oddIndex += 2;
        }
    }

    return answer;
}

int main() {
    vector<int> nums0 {4,2,5,7};
    vector<int> nums1 {2,3};

    vector<int> ans0 = sortArrayByParityII(nums0);
    vector<int> ans1 = sortArrayByParityII(nums1);

    for (int iter : ans0) {
        cout << iter << " ";
    } cout << endl; // [4,5,2,7] 

    for (int iter : ans1) {
        cout << iter << " ";
    } cout << endl; // [2,3]

    return 0;
}

