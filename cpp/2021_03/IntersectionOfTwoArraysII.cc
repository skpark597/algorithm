/* 350. Intersection of Two Arrays II */
/** Given two integer arrays nums1 and nums2, return an array of their intersection. 
 *  Each element in the result must appear as many times as it shows in both arrays and 
 *  you may return the result in any order.
 * 
 *  Example 1:
 *  Input: nums1 = [1,2,2,1], nums2 = [2,2]
 *  Output: [2,2]
 * 
 *  Example 2:
 *  Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 *  Output: [4,9]
 *  Explanation: [9,4] is also accepted.
 * 
 *  Constraints:
 *  1 <= nums1.length, nums2.length <= 1000
 *  0 <= nums1[i], nums2[i] <= 1000
 * 
 *  Follow up:
 *  What if the given array is already sorted? How would you optimize your algorithm?
 *  What if nums1's size is small compared to nums2's size? Which algorithm is better?
 *  What if elements of nums2 are stored on disk, and the memory is limited such that you 
 *  cannot load all elements into the memory at once? **/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> answer;
    unordered_map<int, int> hashTable;

    for (int iter : nums1) {
        if (hashTable.count(iter) > 0) {
            hashTable[iter]++;
        } else {
            hashTable[iter] = 1;
        }
    }

    for (int iter : nums2) {
        if (hashTable.count(iter) > 0 && hashTable[iter] > 0) {
            answer.push_back(iter);
            hashTable[iter]--;
        }
    }

    return answer;
}

int main() {
    vector<int> nums01 {1,2,2,1};
    vector<int> nums02 {2,2};

    vector<int> nums11 {4,9,5};
    vector<int> nums12 {9,4,9,8,4};

    vector<int> ans0 = intersect(nums01, nums02);
    vector<int> ans1 = intersect(nums11, nums12);

    for (int iter : ans0) {
        cout << iter << " ";
    } cout << endl; // [2,2]

    for (int iter : ans1) {
        cout << iter << " ";
    } cout << endl; // [4,9]

    return 0;
}
