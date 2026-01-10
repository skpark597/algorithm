/** 313. Super Ugly Number */
/** A super ugly number is a positive integer whose prime factors are in the array primes.
 *  Given an integer n and an array of integers primes, return the nth super ugly number.
 *  The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 * 
 *  Example 1:
 *  Input: n = 12, primes = [2,7,13,19]
 *  Output: 32
 *  Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
 * 
 *  Example 2:
 *  Input: n = 1, primes = [2,3,5]
 *  Output: 1
 *  Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
 * 
 *  Constraints:
 *  1 <= n <= 10^6
 *  1 <= primes.length <= 100
 *  2 <= primes[i] <= 1000
 *  primes[i] is guaranteed to be a prime number.
 *  All the values of primes are unique and sorted in ascending order. **/

#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <iostream>

using namespace std;

void fillPriorityQueue(int n, int start, vector<int> &primes, set<int> &nums) {
    if (n == 0) return;
    if (start == primes.size()-1) {
        nums.insert(pow(primes[start], n));
        return;
    }

    for (int i = n; i > 0; --i) {
        nums.insert(pow(primes[start], i));
        fillPriorityQueue(n-i, start+1, primes, nums);
    }

    fillPriorityQueue(n, start+1, primes, nums);
}

int nthSuperUglyNumber(int n, vector<int> &primes) {
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> nums;
    int count = 1;
    nums.insert(1);

    for (int i = 1; i <= n; ++i) {
        if (pow(primes[0], i) > 1000) break;
        fillPriorityQueue(i, 0, primes, nums);
    }

    for (int i = 0; i < n-1; ++i) pq.pop();
    return pq.top();
}

int main() {
    vector<int> primes0 {2,7,13,19};
    vector<int> primes1 {2,3,5};
    
    int ans0 = nthSuperUglyNumber(12, primes0);
    int ans1 = nthSuperUglyNumber(1, primes1);

    cout << ans0 << endl; // 32
    cout << ans1 << endl; // 1

    return 0;
}

