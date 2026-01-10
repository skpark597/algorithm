/** 978. Longest Turbulent Subarray **/
/** Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
 *  A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
 *  More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
 * 
 *  For i <= k < j:
 *  arr[k] > arr[k + 1] when k is odd, and
 *  arr[k] < arr[k + 1] when k is even.
 *  Or, for i <= k < j:
 *  arr[k] > arr[k + 1] when k is even, and
 *  arr[k] < arr[k + 1] when k is odd
 * 
 *  Example 1:
 *  Input: arr = [9,4,2,10,7,8,8,1,9]
 *  Output: 5
 *  Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
 * 
 *  Example 2:
 *  Input: arr = [4,8,12,16]
 *  Output: 2
 *  
 *  Example 3:
 *  Input: arr = [100]
 *  Output: 1
 * 
 *  Constraints:
 *  1 <= arr.length <= 4 * 10^4
 *  0 <= arr[i] <= 10^9 **/

#include <iostream>
#include <vector>

using namespace std;

int getStatus(int prev, int cur) {
    if (prev == cur) return 0;
    return prev < cur ? 1 : -1;
}

int getCount(int prevStatus, int curStatus, int count) {
    if (curStatus == 0) return 1;
    return prevStatus == curStatus ? 2 :count + 1;
}

// decrease : -1 , increase : 1, same : 0
int maxTurbulenceSize(vector<int> &arr) {
    int status = 0;
    int count = 1;
    int answer = 0;

    if (arr.size() == 1) return 1;

    for (int i = 1; i < arr.size(); ++i) {
        int curStatus = getStatus(arr[i-1], arr[i]);
        count = getCount(status, curStatus, count);
        answer = max(answer, count);
        status = curStatus;
    }

    return answer;
}

int main() {
    vector<int> arr0 {9,4,2,10,7,8,8,1,9};
    vector<int> arr1 {4,8,12,16};
    vector<int> arr2 {100};

    int ans0 = maxTurbulenceSize(arr0);
    int ans1 = maxTurbulenceSize(arr1);
    int ans2 = maxTurbulenceSize(arr2);

    cout << ans0 << endl; // 5
    cout << ans1 << endl; // 2
    cout << ans2 << endl; // 1

    return 0;
}


