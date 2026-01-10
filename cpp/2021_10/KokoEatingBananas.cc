/* 875. Koko Eating Bananas */
/** Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
 *  The guards have gone and will come back in h hours.
 *  Koko can decide her bananas-per-hour eating speed of k. 
 *  Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
 *  If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
 *  Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
 *  Return the minimum integer k such that she can eat all the bananas within h hours.
 * 
 *  Example 1:
 *  Input: piles = [3,6,7,11], h = 8
 *  Output: 4
 * 
 *  Example 2:
 *  Input: piles = [30,11,23,4,20], h = 5
 *  Output: 30
 * 
 *  Example 3:
 *  Input: piles = [30,11,23,4,20], h = 6
 *  Output: 23
 * 
 *  Constraints:
 *  1 <= piles.length <= 10^4
 *  piles.length <= h <= 10^9
 *  1 <= piles[i] <= 10^9 **/

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int collapsedTime(vector<int> &piles, int k)
{
    int total = 0;
    for (int pile : piles)
        total += ceil((double)pile / k);

    return total;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1;
    int right = 1;
    int middle, time;

    for (int pile : piles)
        right = max(right, pile);

    while (left <= right)
    {
        middle = left + (right - left) / 2;
        time = collapsedTime(piles, middle);

        if (time <= h)
            right = middle - 1;
        else
            left = middle + 1;
    }

    return left;
}

int main()
{
    vector<int> piles0{3, 6, 7, 11};
    vector<int> piles1{30, 11, 23, 4, 20};
    vector<int> piles2{30, 11, 23, 4, 20};

    int ans0 = minEatingSpeed(piles0, 8);
    int ans1 = minEatingSpeed(piles1, 5);
    int ans2 = minEatingSpeed(piles2, 6);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // 30
    cout << ans2 << endl; // 23
}
