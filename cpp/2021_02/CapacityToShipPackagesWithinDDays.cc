/** 1011. Capacity To Ship Packages Within D Days */
/** A conveyor belt has packages that must be shipped from one port to another within D days.
 *  The ith package on the conveyor belt has a weight of weights[i]. 
 *  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
 *  We may not load more weight than the maximum weight capacity of the ship.
 *  Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.
 * 
 *  Example 1:
 *  Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
 *  Output: 15
 *  Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
 *  1st day: 1, 2, 3, 4, 5
 *  2nd day: 6, 7
 *  3rd day: 8
 *  4th day: 9
 *  5th day: 10
 *  Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
 * 
 *  Example 2:
 *  Input: weights = [3,2,2,4,1,4], D = 3
 *  Output: 6
 *  Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
 *  1st day: 3, 2
 *  2nd day: 2, 4
 *  3rd day: 1, 4
 * 
 *  Example 3:
 *  Input: weights = [1,2,3,1,1], D = 4
 *  Output: 3
 *  Explanation:
 *  1st day: 1
 *  2nd day: 2
 *  3rd day: 3
 *  4th day: 1, 1
 * 
 *  Constraints:
 *  1 <= D <= weights.length <= 5 * 10^4
 *  1 <= weights[i] <= 500 **/

#include <vector>
#include <iostream>

using namespace std;

int shipWithinDays(vector<int> &weights, int D) {
    int left = 0;
    int right = 0;
    int middle, weight, count;
    bool fail;

    for (int i = 0; i < weights.size(); ++i) {
        right += weights[i];
    }

    while (left <= right) {
        weight = 0;
        count = 1;
        fail = false;
        middle = (left + right) / 2;
        
        for (int i = 0; i < weights.size(); ++i) {
            weight += weights[i];

            if (weights[i] > middle) {
                fail = true;
                break;
            } else if (weight > middle) {
                weight = weights[i];
                count++;
            }
        }
        
        if (count > D || fail) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return left;
}

int main() {
    vector<int> weights0 {1,2,3,4,5,6,7,8,9,10};
    int ans0 = shipWithinDays(weights0, 5);

    vector<int> weights1 {3,2,2,4,1,4};
    int ans1 = shipWithinDays(weights1, 3);

    vector<int> weights2 {1,2,3,1,1};
    int ans2 = shipWithinDays(weights2, 4);

    vector<int> weights3 {147,73,265,305,191,152,192,293,309,292,182,157,381,287,73,162,313,366,346,47};
    int ans3 = shipWithinDays(weights3, 10);

    cout << ans0 << endl; // 15
    cout << ans1 << endl; // 6
    cout << ans2 << endl; // 3
    cout << ans3 << endl; // 602

    return 0;
}
