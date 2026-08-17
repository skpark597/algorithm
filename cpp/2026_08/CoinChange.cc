/** 322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a
total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4 */

#include <cassert>
#include <climits>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
  const int INF = INT_MAX;
  vector<int> dp(amount + 1, INF);
  dp[0] = 0;

  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      int rem = i - coin;
      if (rem >= 0 && dp[rem] != INF) dp[i] = min(dp[i], dp[rem] + 1);
    }
  }

  return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
  vector<int> coins0{1, 2, 5};
  vector<int> coins1{2};
  vector<int> coins2{1};

  int amount0 = 11;
  int amount1 = 3;
  int amount2 = 0;

  int ret0 = coinChange(coins0, amount0);
  int ret1 = coinChange(coins1, amount1);
  int ret2 = coinChange(coins2, amount2);

  assert(ret0 == 3);
  assert(ret1 == -1);
  assert(ret2 == 0);

  return 0;
}