/** 1200. Minimum Absolute Difference */
/** Given an array of distinct integers arr, 
 *  find all pairs of elements with the minimum absolute difference of any two elements. 
 *  Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
 * 
 *  a, b are from arr
 *  a < b
 *  b - a equals to the minimum absolute difference of any two elements in arr
 * 
 *  Example 1:
 *  Input: arr = [4,2,1,3]
 *  Output: [[1,2],[2,3],[3,4]]
 *  Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
 * 
 *  Example 2:
 *  Input: arr = [1,3,6,10,15]
 *  Output: [[1,3]]
 * 
 *  Example 3:
 *  Input: arr = [3,8,-10,23,19,-4,-14,27]
 *  Output: [[-14,-10],[19,23],[23,27]]
 * 
 *  Constraints: 
 *  2 <= arr.length <= 10^5 
 *  -10^6 <= arr[i] <= 10^6 **/

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    int minDiff = INT_MAX;
    vector<vector<int>> answer;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size()-1; ++i) {
        minDiff = min(minDiff, arr[i+1]-arr[i]);
    }

    for (int i = 0; i < arr.size()-1; ++i) {
        if (minDiff == arr[i+1] - arr[i]) {
            answer.push_back(vector<int>{arr[i], arr[i+1]});
        }
    }

    return answer;
}

int main() {
    vector<int> arr0 {4,2,1,3};
    vector<vector<int>> ans0 = minimumAbsDifference(arr0);

    vector<int> arr1 {1,3,6,10,15};
    vector<vector<int>> ans1 = minimumAbsDifference(arr1);

    vector<int> arr2 {3,8,-10,23,19,-4,-14,27};
    vector<vector<int>> ans2 = minimumAbsDifference(arr2);

    for (vector<int> iter0 : ans0) {
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        } cout << endl;
    } cout << endl;

    for (vector<int> iter0 : ans1) {
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        } cout << endl;
    } cout << endl;

    for (vector<int> iter0 : ans2) {
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        } cout << endl;
    } cout << endl;

}






