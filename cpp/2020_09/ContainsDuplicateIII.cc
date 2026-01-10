/* 220. Contains Duplicate III */
/** Given an array of integers, find out whether there are two distinct indices i and j 
 *  in the array such that the absolute difference between nums[i] and nums[j] is at most t 
 *  and the absolute difference between i and j is at most k.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3,1], k = 3, t = 0
 *  Output: true
 * 
 *  Example 2:
 *  Input: nums = [1,0,1,1], k = 1, t = 2
 *  Output: true
 * 
 *  Example 3:
 *  Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 *  Output: false
 * 
 *  Constraints:
 *  0 <= nums.length <= 2 * 10^4
 *  -2^31 <= nums[i] <= 2^31 - 1
 *  0 <= k <= 10^4
 *  0 <= t <= 2^31 - 1 **/

#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

// 시간 초과 뜬 풀이 ㅜㅜ multimap을 이용해서 다시 풀어보자

void swap (vector<int> &sequence, int left, int right) {
    int temp = sequence[left];
    sequence[left] = sequence[right];
    sequence[right] = temp;
}

int partition (vector<int> &sequence, int left, int right) {
    int low = left;
    int high = right+1;
    int pivot = sequence[left];

    do {
        do {
            low++;
        } while (low <= right && sequence[low] <= pivot);

        do {
            high--;
        } while (high > left && sequence[high] > pivot);

        if (low <high) {
            swap (sequence, low, high);
        }
    } while (low < high);

    swap (sequence, left, high);
    return high;
}

void quickSort (vector<int> &sequence, int left, int right) {
    if (left >= right) return;

    int q = partition(sequence, left, right);
    quickSort (sequence, left, q-1);
    quickSort (sequence, q+1, right);
}

// interval에 2개 이상의 element가 있을 때 사용
bool existsSuchIndices (vector<int> &interval, int t) {
    for (int j=0; j < interval.size()-1; ++j) {
        double difference = (double)(interval[j]) - (double)(interval[j+1]);
        if (abs(difference) <= t ) return true;
    }

    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    vector<int> interval;
    bool exists = false;

    if (nums.empty() || nums.size() ==1) return false;

    for (int i=0;i < k+1; ++i) {
        if (i < nums.size()) interval.push_back(nums[i]);
    }

    quickSort(interval, 0, interval.size()-1);
    exists = existsSuchIndices(interval, t);
    if (exists || nums.size() <= k+1) return exists;

    for (int i=0; i< nums.size()-k-1; ++i) {
        vector<int> temp;
        int j=0;
        int newElem = nums[k+1+i];
        int deletedElem = nums[i];
        temp = interval;
        interval.clear();

        while (j < temp.size()) {
            if (temp[j] >= newElem && (j==0 || temp[j-1] < newElem)) {
                interval.push_back(newElem);
                newElem = INT_MAX;
                continue;
            } else if (temp[j] != deletedElem) {
                interval.push_back(temp[j]);
            }
            j++;
        }

        exists = existsSuchIndices(interval, t);
        if (exists) return true;
    }

    return false;
}

int main() {
    //vector<int> sequence {5,3,8,4,9,1,6,2,7};
    //vector<int> sequence {1,4,5,2,7,6};
    //quickSort (sequence, 0, sequence.size()-1);

    //vector<int> nums {1,2,3,1};
    //vector<int> nums {1,0,1,1};
    //vector<int> nums {1,5,9,1,5,9};
    vector<int> nums {2147483647, -2147483647};
    bool answer = containsNearbyAlmostDuplicate(nums, 1,2147483647);

    return 0;
}











