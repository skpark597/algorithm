/* 1007. Minimum Domino Rotations For Equal Row - Discussion에서 본 풀이*/

/** In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  
 *  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
 *  
 *  We may rotate the ith domino, so that A[i] and B[i] swap values.
 *  Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
 *  If it cannot be done, return -1.
 * 
 *  Example 1:
 *  Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
 *  Output: 2
 *  Explanation: 
 *  The first figure represents the dominoes as given by A and B: before we do any rotations.
 *  If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
 * 
 *  Example 2:
 *  Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
 *  Output: -1
 *  Explanation: 
 *  In this case, it is not possible to rotate the dominoes to make one row of values equal.
 * 
 *  Constraints:
 *  2 <= A.length == B.length <= 2 * 104
 *  1 <= A[i], B[i] <= 6 **/

#include <iostream>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;

int minDominoRotations(vector<int>& A, vector<int>& B) {
    vector<int> a_cnts (6, 0);
    vector<int> b_cnts (6, 0);
    vector<int> same_cnts (6, 0);
    int minSwap = INT_MAX;

    for (int i = 0; i < A.size(); ++i) {
        a_cnts[A[i]-1]++;
        b_cnts[B[i]-1]++;
        if (A[i] == B[i]) same_cnts[A[i]-1]++;
    }

    for (int i = 0; i < 6; ++i) {
        if (a_cnts[i]+b_cnts[i]-same_cnts[i] == A.size()) {
            minSwap = min (minSwap, min(a_cnts[i],b_cnts[i])-same_cnts[i]);
        }
    }

    return minSwap == INT_MAX ? -1 : minSwap;
}

int main() {
    vector<int> A {2,1,2,4,2,2};
    vector<int> B {5,2,6,2,3,2};

    //vector<int> A {3,5,1,2,3};
    //vector<int> B {3,6,3,3,4};

    //vector<int> A {1,1,1,1,1,1,1,1};
    //vector<int> B {1,1,1,1,1,1,1,1};

    //vector<int> A {2,1,2,4,2,2};
    //vector<int> B {5,2,6,2,3,2};
    
    //vector<int> A {2,3,2,1,1,1,2,2};
    //vector<int> B {2,1,2,1,1,3,1,1};

    int answer = minDominoRotations(A,B);

    cout << answer << endl;

    return 0;
}

















