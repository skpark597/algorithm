/** 746. Min Cost Climbing Stairs */
/** You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
 *  Once you pay the cost, you can either climb one or two steps.
 * 
 *  You can either start from the step with index 0, or the step with index 1.
 *  Return the minimum cost to reach the top of the floor.
 * 
 *  Example 1:
 *  Input: cost = [10,15,20]
 *  Output: 15
 *  Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
 * 
 *  Example 2:
 *  Input: cost = [1,100,1,1,1,100,1,1,100,1]
 *  Output: 6
 *  Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
 * 
 *  Constraints:
 *  2 <= cost.length <= 1000
 *  0 <= cost[i] <= 999 **/

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int cache[1001];

int minCostClimbingStairs(vector<int> &cost) {
    int destination = cost.size();
    memset(cache, 0, sizeof(cache));

    if (cost.size() == 1) return 0;

    cache[0] = 0;
    cache[1] = 0;

    for (int i = 2; i <= destination; ++i) {
        cache[i] = min(cache[i-1]+cost[i-1], cache[i-2]+cost[i-2]);
    }

    return cache[destination];
}

int main() {
    vector<int> cost0 {10,15,20};
    vector<int> cost1 {1,100,1,1,1,100,1,1,100,1};

    int ans0 = minCostClimbingStairs(cost0);
    int ans1 = minCostClimbingStairs(cost1);

    cout << ans0 << endl; // 15
    cout << ans1 << endl; // 6

    return 0;
}