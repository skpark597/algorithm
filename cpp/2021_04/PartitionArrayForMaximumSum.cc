/** 1043. Partition Array for Maximum Sum */
/** Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. 
 *  After partitioning, each subarray has their values changed to become the maximum value of that subarray.
 *  Return the largest sum of the given array after partitioning.
 * 
 *  Example 1:
 *  Input: arr = [1,15,7,9,2,5,10], k = 3
 *  Output: 84
 *  Explanation: arr becomes [15,15,15,9,10,10,10]
 * 
 *  Example 2:
 *  Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
 *  Output: 83
 * 
 *  Example 3:
 *  Input: arr = [1], k = 1
 *  Output: 1
 * 
 *  Constraints:
 *  1 <= arr.length <= 500
 *  0 <= arr[i] <= 10^9
 *  1 <= k <= arr.length **/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int cache[501];

int maxSum(vector<int> &arr, int start, int k) {
    int &answer = cache[start];
    int number = 0;

    if (arr.size() - start <= k) {
        for (int i = start; i < arr.size(); ++i) {
            number = max(number, arr[i]);      
        }
        return number * (arr.size() - start);
    }

    if (answer != -1) return answer;

    for (int i = start; i < start + k; ++i) {
        number = max(number, arr[i]);
        answer = max(answer, number * (i-start+1) + maxSum(arr, i+1, k));
    }

    return answer;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    for (int i = 0; i < 501; ++i) cache[i] = -1;
    return maxSum(arr, 0, k);
}

int main() {
    vector<int> arr0 {1,15,7,9,2,5,10};
    vector<int> arr1 {1,4,1,5,7,3,6,1,9,9,3};
    vector<int> arr2 {1};

    int ans0 = maxSumAfterPartitioning(arr0, 3);
    int ans1 = maxSumAfterPartitioning(arr1, 4);
    int ans2 = maxSumAfterPartitioning(arr2, 1);

    cout << ans0 << endl; // 84
    cout << ans1 << endl; // 83
    cout << ans2 << endl; // 1

    return 0;
}

