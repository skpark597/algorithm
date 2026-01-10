/* 845. Longest Mountatin in Array */
/** Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
 *  B.length >= 3
 *  There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
 *  (Note that B could be any subarray of A, including the entire array A.)
 * 
 *  Given an array A of integers, return the length of the longest mountain. 
 *  Return 0 if there is no mountain.
 * 
 *  Example 1
 *  Input: [2,1,4,7,3,2,5]
 *  Output: 
 *  Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
 * 
 *  Example 2:
 *  Input: [2,2,2]
 *  Output: 0
 *  Explanation: There is no mountain.
 * 
 *  Note:
 *  0 <= A.length <= 10000
 *  0 <= A[i] <= 10000
 * 
 *  Follow up:
 *  Can you solve it using only one pass?
 *  Can you solve it in O(1) space? **/

#include <vector>
#include <iostream>
using namespace std;

int longestMountain(vector<int>& A) {
    int length = 0;
    int leftCompare = -1;
    int rightCompare = -1;
    int index = -1;

    if (A.size() <= 1) return 0;

    for (int i = 0; i < A.size(); ++i) {
        leftCompare = (i == 0) ? 0 : A[i]-A[i-1];
        rightCompare = (i == A.size()-1) ? 0 : A[i]-A[i+1];

        if (leftCompare < 0 && rightCompare < 0) {
            length = (index != -1) ? max(length, i-index+1) : length;
            index = i;
        } else if (leftCompare == 0 && rightCompare < 0) {
            index = i;
        } else if (leftCompare > 0 && rightCompare == 0) {
            index = -1;
        } else if (leftCompare < 0 && rightCompare == 0) {
            length = (index != -1) ? max(length, i-index+1) : length;
            index = -1;
        }
    }

    return length;
}

int main() {
    vector<int> A {3,3,2,2,1,1,0,0,0,1,3,3,3,3,0,0,2,0,3,2,2,0,0,3,2,0,1,0,3,1,1,1,0,1,0,3,1,
    3,2,2,3,2,1,1,1,3,3,0,2,2,0,3,0,3,3,1,1,2,0,0,1,3,0,1,3,0,0,1,2,0,0,0,0,0,2,
    0,1,3,0,1,3,3,3,1,0,3,3,1,0,1,0,2,3,1,1,2,3,1,2,3};
    //vector<int> A {2,1,4,7,3,2,5}; 
    //vector<int> A {1,1,0,0,1,0};

    int answer = longestMountain(A);
    cout << answer << endl;
    return 0;
}
