/* 307. Range Sum Query - Mutable */
/** Given an array nums and two types of queries where you should update the value of an index in the array, 
 *  and retrieve the sum of a range in the array. Implement the NumArray class:
 * 
 *  NumArray(int[] nums) Initializes the object with the integer array nums.
 *  void update(int index, int val) Updates the value of nums[index] to be val.
 *  int sumRange(int left, int right) Returns the sum of the subarray nums[left, right] (i.e., nums[left] + nums[left + 1], ..., nums[right]).
 * 
 *  Example 1:
 *  Input
 *  ["NumArray", "sumRange", "update", "sumRange"]
 *  [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 *  Output
 *  [null, 9, null, 8]
 *  
 *  Explanation
 *  NumArray numArray = new NumArray([1, 3, 5]);
 *  numArray.sumRange(0, 2); // return 9 = sum([1,3,5])
 *  numArray.update(1, 2);   // nums = [1,2,5]
 *  numArray.sumRange(0, 2); // return 8 = sum([1,2,5])
 * 
 *  Constraints:
 *  1 <= nums.length <= 3 * 104
 *  -100 <= nums[i] <= 100
 *  0 <= index < nums.length
 *  -100 <= val <= 100
 *  0 <= left <= right < nums.length
 *  At most 3 * 104 calls will be made to update and sumRange **/

#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class NumArray {
    private:
    vector<int> tree;
    vector<int> numsCopy;

    int partialSum(int index) {
        // 0부터 index 까지 element들의 sum
        int ret = 0;
        int pos = index+1;

        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }

        return ret;
    }

    public:
    NumArray(vector<int> &nums) {
        numsCopy = nums;
        tree.resize(nums.size()+1, 0);

        for (int i = 0; i < nums.size(); ++i) {
            add(i, nums[i]);
        }
    }

    void add(int index, int val) {
        int pos = index+1;

        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
    
    void update(int index, int val) {
        int diff = val-numsCopy[index];
        numsCopy[index] = val;
        add(index, diff);
    }
    
    int sumRange(int left, int right) {
        return partialSum(right) - partialSum(left-1);
    }
};

int main() {
    vector<int> nums0 {1,3,5};
    NumArray numArray0(nums0);
    int sum00 = numArray0.sumRange(0, 2); 
    numArray0.update(1, 2);   // nums0 = [1,2,5]
    int sum01 = numArray0.sumRange(0, 2); 

    vector<int> nums1 {9, -8};
    NumArray numArray1(nums1);
    numArray1.update(0, 3); //nums1 = [3,-8]
    int sum10 = numArray1.sumRange(1,1);
    int sum11 = numArray1.sumRange(0,1);
    numArray1.update(1, -3); //nums1 = [3,-3]
    int sum12 = numArray1.sumRange(0,1);

    cout << sum00 << endl; // return 9 = sum([1,3,5])
    cout << sum01 << endl; // return 8 = sum([1,2,5])

    cout << sum10 << endl; // return -8
    cout << sum11 << endl; // return -5
    cout << sum12 << endl; // return 0

    return 0;
}

