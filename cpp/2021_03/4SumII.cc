/* 454. 4Sum II */
/** Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) 
 *  there are such that A[i] + B[j] + C[k] + D[l] is zero.
 *  To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
 *  All integers are in the range of -2^28 to 2^28 - 1 and the result is guaranteed to be at most 2^31 - 1.
 * 
 *  Example:
 *  Input:
 *  A = [ 1, 2]
 *  B = [-2,-1]
 *  C = [-1, 2]
 *  D = [ 0, 2]
 * 
 *  Output: 2
 *  Explanation:
 *  The two tuples are:
 *  1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 *  2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0 **/

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int count = 0;
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            if (map1.count(A[i]+B[j])) {
                map1[A[i]+B[j]]++;
            } else {
                map1[A[i]+B[j]] = 1;
            }
        }
    }

     for (int i = 0; i < C.size(); ++i) {
        for (int j = 0; j < D.size(); ++j) {
            if (map2.count(C[i]+D[j])) {
                map2[C[i]+D[j]]++;
            } else {
                map2[C[i]+D[j]] = 1;
            }
        }
    }

    for (auto iter : map1) {
        if (map2.count(-iter.first)) count += iter.second * map2[-iter.first];
    }

    return count;
}

int main() {
    vector<int> A0 {1, 2};
    vector<int> B0 {-2, -1};
    vector<int> C0 {-1, 2};
    vector<int> D0 {0, 2};

    vector<int> A1 {-1,-1};
    vector<int> B1 {-1,1};
    vector<int> C1 {-1,1};
    vector<int> D1 {1,-1};

    int ans0 = fourSumCount(A0, B0, C0, D0);
    int ans1 = fourSumCount(A1, B1, C1, D1);

    cout << ans0 << endl; // 2
    cout << ans1 << endl; // 6

    return 0;
}
