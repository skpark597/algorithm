/* 283. Move Zeroes */
/** Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *  
 *  Example:
 *  Input: [0,1,0,3,12]
 *  Output: [1,3,12,0,0]
 * 
 *  Note:
 *  You must do this in-place without making a copy of the array.
 *  Minimize the total number of operations. **/

#include <vector>
#include <iostream>

using namespace std;

void swap(vector<int> &nums, int idx1, int idx2) {
    int temp = nums[idx1];
    nums[idx1] = nums[idx2];
    nums[idx2] = temp;
}

void moveZeroes(vector<int> &nums) {
    int start = 0;
    int end = 1;

    if (nums.size() <= 1) return;

    while (end < nums.size()) {
        if (start == end) {
            end++;
            continue;
        }

        if (nums[start] == 0 && nums[end] != 0) {
            swap(nums, start, end);
        }

        if (nums[start] != 0) start++;
        if (nums[end] == 0 )end++;
    }

}

int main() {
    vector<int> nums0 {0,1,0,3,12};
    moveZeroes(nums0);

    vector<int> nums1 {2,1};
    moveZeroes(nums1);

    for (int i = 0; i < nums0.size(); ++i) {
        cout << nums0[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}

