/* 31. Next Permutation */
/** Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *  If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
 *  The replacement must be in place and use only constant extra memory.
 *  
 *  Example 1:
 *  Input: nums = [1,2,3]
 *  Output: [1,3,2]
 * 
 *  Example 2:
 *  Input: nums = [3,2,1]
 *  Output: [1,2,3]
 * 
 *  Example 3:
 *  Input: nums = [1,1,5]
 *  Output: [1,5,1]
 * 
 *  Example 4:
 *  Input: nums = [1]
 *  Output: [1]
 * 
 *  Constraints:
 *  1 <= nums.length <= 100
 *  0 <= nums[i] <= 100 **/

/* 내가 처음 생각한 풀이*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void nextPermutation(vector<int> &nums) {
    int index1 = -1;
    int index2 = -1;
    int size = nums.size();

    for (int i = 0; i < size-1; ++i) {
        if (nums[i] < nums[i+1]) index1 = i;
    }

    if (index1 == -1) {
        sort(nums.begin(), nums.end());
        return;
    }

    index2 = index1+1;

    for (int i = index2+1; i < size; ++i) {
        if (nums[i] > nums[index1] && nums[i] < nums[index2]) index2 = i;
    }

    swap(nums[index1], nums[index2]);
    sort(nums.begin()+index1+1, nums.end());
}

int main() {
    vector<int> nums0 {1,2,3};
    vector<int> nums1 {3,2,1};
    vector<int> nums2 {1,1,5};
    vector<int> nums3 {1};
    vector<int> nums4 {1,3,4,5,1};
    vector<int> nums5 {1,3,2};

    nextPermutation(nums0);
    nextPermutation(nums1);
    nextPermutation(nums2);
    nextPermutation(nums3);
    nextPermutation(nums4);
    nextPermutation(nums5);

    for (int iter : nums0) {
        cout << iter << " ";
    }
    cout << endl; // 1 3 2

    for (int iter : nums1) {
        cout << iter << " ";
    }
    cout << endl; // 1 2 3

    for (int iter : nums2) {
        cout << iter << " ";
    }
    cout << endl; // 1 5 1

    for (int iter : nums3) {
        cout << iter << " ";
    }
    cout << endl; // 1 

    for (int iter : nums4) {
        cout << iter << " ";
    }
    cout << endl; // 1 3 5 1 4

    for (int iter : nums5) {
        cout << iter << " ";
    }
    cout << endl; // 2 1 3

    return 0;
}

