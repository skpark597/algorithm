/* 967. Numbers With Same Consecutive Differences */
/** Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.
 *  Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.
 *  You may return the answer in any order.
 * 
 *  Example 1:
 *  Input: n = 3, k = 7
 *  Output: [181,292,707,818,929]
 *  Explanation: Note that 070 is not a valid number, because it has leading zeroes.
 * 
 *  Example 2:
 *  Input: n = 2, k = 1
 *  Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 * 
 *  Example 3:
 *  Input: n = 2, k = 0
 *  Output: [11,22,33,44,55,66,77,88,99]
 * 
 *  Example 4:
 *  Input: n = 2, k = 2
 *  Output: [13,20,24,31,35,42,46,53,57,64,68,75,79,86,97]
 * 
 *  Constraints:
 *  2 <= n <= 9
 *  0 <= k <= 9 **/

#include <vector>
#include <list>
#include <math.h>

using namespace std;

list<int> cache[10][10][10];

list<int> numsSameConsecDiff(int first, int N, int K) {
    list<int> &newList = cache[first][N][K];
    list<int> temp;

    if (N == 0) return list<int> {0};
    if (N == 1) return list<int> {first};
    if (!newList.empty()) return newList;
    if (K == 0) {
        int number = 0;
        for (int i=0; i < N; ++i) {
            number += first * pow(10,i);
        }
        return list<int> {number};
    }


    if (first-K == 0) {
        temp = numsSameConsecDiff(first, N-2,K);
        for (int &iter : temp) {
            newList.push_back(first *pow(10,N-1) + iter);
        }
    }

    if (first-K > 0) {
        temp = numsSameConsecDiff(first-K, N-1, K);
        for (int &iter : temp) {
            newList.push_back(first *pow(10,N-1) + iter);
        }
    }

    if (first+K < 10) {
        temp = numsSameConsecDiff(first+K, N-1, K);
        for (int &iter : temp) {
            newList.push_back(first *pow(10,N-1) + iter);
        }
    }

    return newList;
}

vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> answer;
    list<int> temp;
    
    if (N == 1) {
        for (int i=0; i<10; ++i) {
            answer.push_back(i);
        }
        return answer;
    }

    for (int i=1; i < 10; ++i) {
        temp = numsSameConsecDiff(i, N, K);
        for (int &iter : temp) {
            answer.push_back(iter);
        }
    }

    return answer;
}

int main() {

    vector<int> answer = numsSameConsecDiff(2, 0);

    return 0;
}





