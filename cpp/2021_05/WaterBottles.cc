/** 1518. Water Bottles */
/** Given numBottles full water bottles, you can exchange numExchange empty water bottles for one full water bottle.
 *  The operation of drinking a full water bottle turns it into an empty bottle.
 *  Return the maximum number of water bottles you can drink.
 * 
 *  Example 1:
 *  Input: numBottles = 9, numExchange = 3
 *  Output: 13
 *  Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
 *  Number of water bottles you can drink: 9 + 3 + 1 = 13.
 * 
 *  Example 2:
 *  Input: numBottles = 15, numExchange = 4
 *  Output: 19
 *  Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
 *  Number of water bottles you can drink: 15 + 3 + 1 = 19.
 * 
 *  Example 3:
 *  Input: numBottles = 5, numExchange = 5
 *  Output: 6
 * 
 *  Example 4:
 *  Input: numBottles = 2, numExchange = 3
 *  Output: 2
 * 
 *  Constraints:
 *  1 <= numBottles <= 100
 *  2 <= numExchange <= 100 **/

#include <vector>
#include <iostream>

using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int answer = numBottles;
    int emptyBottles = numBottles;

    while (emptyBottles >= numExchange) {
        int exchange = emptyBottles / numExchange;
        answer += exchange;
        emptyBottles = exchange + emptyBottles % numExchange;
    }

    return answer;
}

int main() {
    int ans0 = numWaterBottles(15, 4);
    int ans1 = numWaterBottles(5, 5);
    int ans2 = numWaterBottles(2, 3);
    int ans3 = numWaterBottles(9, 3);

    cout << ans0 << endl; // 19
    cout << ans1 << endl; // 6
    cout << ans2 << endl; // 2
    cout << ans3 << endl; // 13

    return 0;
}

