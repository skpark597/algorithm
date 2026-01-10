/* 714. Best Time to Buy and Sell Stock with Transaction Fee */
/** You are given an array prices where prices[i] is the price of a given stock on the ith day, 
 *  and an integer fee representing a transaction fee.
 *  Find the maximum profit you can achieve. You may complete as many transactions as you like, 
 *  but you need to pay the transaction fee for each transaction.
 *  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 * 
 *  Example 1:
 *  Input: prices = [1,3,2,8,4,9], fee = 2
 *  Output: 8
 *  Explanation: The maximum profit can be achieved by:
 *  - Buying at prices[0] = 1
 *  - Selling at prices[3] = 8
 *  - Buying at prices[4] = 4
 *  - Selling at prices[5] = 9
 *  The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 *  Example 2:
 *  Input: prices = [1,3,7,5,10,3], fee = 3
 *  Output: 6
 * 
 *  Constraints:
 *  1 <= prices.length <= 5 * 10^4
 *  1 <= prices[i] < 5 * 10^4
 *  0 <= fee < 5 * 10^4 **/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int cache[5000];

// 아래는 solution을 보고 다시 구현한 풀이. 신박하네
int maxProfit(vector<int> &prices, int fee) {
    int cash = 0;
    int hold = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }

    return cash;
}

// 아래는 처음으로 생각했던 풀이. 시간초과로 Fail.
int maxProfit2(vector<int> &prices, int fee) {
    memset(cache, 0, sizeof(cache));

    for (int i = 1; i < prices.size(); ++i) {
        cache[i] = max(cache[i-1], prices[i]-prices[0]-fee);
        for (int j = 1; j < i; ++j) {
            cache[i] = max(cache[i], prices[i]-prices[j]-fee+cache[j-1]);
        }
    }

    return cache[prices.size()-1];
}

int main() {
    vector<int> prices0 {1,3,2,8,4,9};
    vector<int> prices1 {1,3,7,5,10,3};

    int ans0 = maxProfit(prices0, 2);
    int ans1 = maxProfit(prices1, 3);

    cout << ans0 << endl; // 8
    cout << ans1 << endl; // 6

    return 0;
}



